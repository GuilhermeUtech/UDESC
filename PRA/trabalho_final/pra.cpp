#include<bits/stdc++.h>

using namespace std;

#define TAM 10000

class Pagina1No{
  pair<double, int> *chaves; 
  int num_chaves;
  Pagina1No **filhos;
  int current_num_keys;
  bool isFolha;

  public:
    Pagina1No(int num_chaves, bool isFolha);
    void insertNonFull(double key, int pos);
    void splitChild(int i, Pagina1No *y);
    void traverse();
    int remover(double chave);
    int search(double key);
    friend class Pagina1;
};

class Pagina1{
    Pagina1No *raiz;
    int num_chaves;

    public:
        Pagina1(int nk){
            raiz = NULL;
            num_chaves = nk;
        }

        int remover(double chave){
            return (raiz == NULL)? (double)-1: raiz->remover(chave);
        }

        void traverse(){
            if( raiz != NULL)
                raiz->traverse();
        }

        long long search(double key){
            return (raiz == NULL)? (double)-1: raiz->search(key);
        }

        void insert(double key, int pos);
};

  typedef struct Registro{
  int id; //identificador único
  char estado[3];
  char cidade[100];
  char fornecedor[100];
  double cnpj; //identificador único
  int preco;
  char bandeira[100];
  char fornecedorCNPJ[100]; //identificador único de string
  } Registro;

  typedef struct ID{
    int id;
    int posicao;
  } ID;

  typedef struct CNPJ{
    double cnpj;
    int posicao;
  } CNPJ;



Pagina1No::Pagina1No (int _num_chaves, bool _isFolha){
  num_chaves = _num_chaves;
  isFolha = _isFolha;
  chaves = new pair<double, int> [2*(num_chaves - 1)];
  filhos = new Pagina1No * [2 * num_chaves];
  current_num_keys = 0;
}

void Pagina1No::traverse(){
  int i;
  for(i=0; i<current_num_keys; i++){
    if(isFolha == false)
        filhos[i]->traverse();
    cout << " [" << chaves[i].first << "," << chaves[i].second << "]";
  }
  if(isFolha == false)
      filhos[i]->traverse();
}

int Pagina1No::search(double chave){
    int i = 0;
    while( i < current_num_keys && chave > chaves[i].first)
        i++;

    if (chaves[i].first == chave)
        return chaves[i].second;

    if( isFolha == true)
        return (double)-1;

    return filhos[i]->search(chave);
}



void Pagina1::insert(double chave, int pos){
    if( raiz == NULL){
        raiz = new Pagina1No(num_chaves, true);
        raiz->chaves[0].first = chave;
        raiz->chaves[0].second = pos;
        raiz->current_num_keys = 1;
    }else{
        if( raiz->current_num_keys == 2 * ( num_chaves - 1)){
            Pagina1No *s = new Pagina1No(num_chaves, false);

            s->filhos[0] = raiz;
            s->splitChild(0, raiz);
            int i = 0;
            if( s->chaves[0].first < chave)
                i++;
            s->filhos[i]->insertNonFull(chave, pos);
            raiz = s;
        } else {
            raiz->insertNonFull(chave, pos);
        }
    }
}

void Pagina1No::insertNonFull(double chave, int pos){
    int i = current_num_keys - 1;
    if( isFolha == true)
    {
        while( i >= 0 && chaves[i].first > chave)
        {
            chaves[i+1].first = chaves[i].first;
            chaves[i+1].second = chaves[i].second;
            i--;
        }
        chaves[i+1].first = chave;
        chaves[i+1].second = pos;
        current_num_keys+=1;
    } else {
        while( i >= 0 && chaves[i].first > chave){
            i--;
        }

        if(filhos[i+1]->current_num_keys == 2 * (num_chaves-1)){
            splitChild(i+1, filhos[i+1]);
            if( chaves[i+1].first < chave)
                i++;
        }
        filhos[i+1]->insertNonFull(chave, pos);
    }
}

void Pagina1No::splitChild(int i, Pagina1No *y){
    Pagina1No *z = new Pagina1No(y->num_chaves, y->isFolha);
    z->current_num_keys = num_chaves - 1;
    for(int j=0; j<num_chaves - 1; j++){
        z->chaves[j].first = y->chaves[j+num_chaves].first;
        z->chaves[j].second = y->chaves[j+num_chaves].second;
    }
    if(y->isFolha == false){
        for(int j=0; j< num_chaves;j++){
            z->filhos[j] = y->filhos[j+num_chaves];
        }
    }
    y->current_num_keys = num_chaves - 1;
    for( int j = current_num_keys; j >= i; j--){
        filhos[j+1] = filhos[j];
    }
    filhos[i+1] = z;
    for(int j = current_num_keys-1; j >= i; j--){
        chaves[j+1].first = chaves[j].first;
        chaves[j+1].second = chaves[j].second;
    }
    chaves[i].first = y->chaves[num_chaves - 1].first;
    chaves[i].second = y->chaves[num_chaves - 1].second;
    current_num_keys+=1;
}

int Pagina1No::remover(double chave){
    int i = 0;
    while( i < current_num_keys && chave > chaves[i].first)
        i++;

    if (chaves[i].first == chave){

        chaves[i].first = -1;
        chaves[i].second = -1;
        return -1;
    } else if(isFolha == true){

        return -1;

    } else {
        return filhos[i]->remover(chave);
    }
}

int main(void){

fstream arquivo;
fstream arq;
arquivo.open("arquivo.dat", ios::in | ios::binary);
fstream id;
fstream cnpj;

int ordem, operacao, metodo, operacao_id;
double operacao_cnpj;
operacao = -1;

cout << "Ordem?" << endl;
cin >> ordem;

Pagina1 p1(ordem);
Pagina1 p2(ordem);

id.open("indice_id.dat", ios::in | ios::binary);
cnpj.open("indice_cnpj.dat", ios::in | ios::binary);

ID* indice_ID = new ID();
CNPJ* indice_CNPJ = new CNPJ();
Registro* registro = new Registro();
Registro* aux = new Registro();

id.seekg(0, ios::beg);
cnpj.seekg(0, ios::beg);

int i=0;

while(i<10){

    id.read((char*) indice_ID, sizeof(ID));
    cnpj.read((char*) indice_CNPJ, sizeof(CNPJ));
    cout << "a" << endl;
    p1.insert(indice_ID->id, indice_ID->posicao);
    p2.insert(indice_CNPJ->cnpj, indice_CNPJ->posicao);
cout << "b" << endl;
    id.seekg(sizeof(ID)*(i+1));
    cnpj.seekg(sizeof(CNPJ)*(i+1));
cout << "c" << endl;
i++;
}
cout << "saiu" << endl;

id.close();
cnpj.close();

while(true){

    cout << "1 - buscar por ID" << endl << "2 - buscar por CNPJ"<< endl << "3 - remover por ID" << endl << "4 - remover por CNPJ"<< endl << "5 - inserir novo registro"<< endl << "0 - para sair " << endl;
    cin >> operacao;

    if(operacao == 1){
    cout << "Digite o ID que você deseja buscar" << endl;
    cin >> operacao_id;
    int pos = p1.search(operacao_id);
    //cout << pos << endl;

    if(pos == -1){
        cout << "Não foi encontrado" << endl;
    }  else {
        arquivo.seekg((pos-1)*sizeof(Registro));
        arquivo.read((char*)registro, sizeof(Registro)); 
        cout << "Índice numérico ID:" << registro->id << endl;
        cout << " Fornecedor: " <<registro->fornecedor << endl << "Índice numérico CNPJ: "<< registro->cnpj << endl << " Preço: R$" << registro->preco << endl;
        cout << " Estado: " << registro->estado << endl << " Cidade: "<< registro->cidade << endl << " Bandeira: " << registro->bandeira << endl;
        cout << "Índice string fornecedorCNPJ: "<<registro->fornecedorCNPJ << endl;
        }
    } else if(operacao == 2){
        cout << "Digite o CNPJ que você deseja buscar" << endl;
        cin >> operacao_cnpj;
        int pos = p2.search(operacao_cnpj);
        //cout << pos;
        cout << "" << endl;

        if(pos == -1){
            cout << "Não foi encontrado" << endl;
            cout << "" << endl;
        } else {
            arquivo.seekg((pos-1)*sizeof(Registro));
            arquivo.read((char*)registro, sizeof(Registro));
            cout << "Índice numérico ID:" << registro->id << endl;
            cout << " Fornecedor: " <<registro->fornecedor << endl << "Índice numérico CNPJ: "<< registro->cnpj << endl << " Preço: R$" << registro->preco << endl;
            cout << " Estado: " << registro->estado << endl << " Cidade: "<< registro->cidade << endl << " Bandeira: " << registro->bandeira << endl;
            cout << "Índice string fornecedorCNPJ: "<<registro->fornecedorCNPJ << endl;
        }

        } else if(operacao == 3){

            int id_remover;
            cout << "Digite o ID que deseja remover" << endl;
            cin >> id_remover;
            p1.remover(id_remover);
            
        } else if(operacao == 4){

            double cnpj_remover;
            cout << "Digite o CNPJ que deseja remover" << endl;
            cin >> cnpj_remover;
            p2.remover(cnpj_remover);

        } else if(operacao == 5){
            i++;
            //arq.open("arquivo.dat", ios::ate | ios::binary);
            cout << "Digite respectivamente: estado, cidade, fornecedor, CNPJ, preço, bandeira" << endl;
            aux->id=i;
            cout << "id: " << i;
            cin >> aux->estado;
            cin >> aux->cidade;
            cin >> aux->fornecedor;
            cin >> aux->cnpj;
            cin >> aux->preco;
            cin >> aux->bandeira;
            strcpy(aux->fornecedorCNPJ, aux->fornecedor);
            char cnpj_string[20];
            sprintf(cnpj_string, "%lf", aux->cnpj);
            strcat(aux->fornecedorCNPJ, cnpj_string);
            strcat(aux->fornecedorCNPJ, "\n");
            cout << aux->fornecedorCNPJ;
            i++; 
            arq.write((char*)aux, sizeof(Registro));
            p1.insert(aux->id, aux->id);
            arq.close();    

        } else if(operacao == 0){
            cout << "Saindo..." << endl;
            cout << "" << endl;
            break;
        }

}
return 0;
}
