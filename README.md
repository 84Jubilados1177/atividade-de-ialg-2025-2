# atividade-de-ialg-2025-2
### trabalho final Ciências da computação

Alunos (10A):

- Isabel Valadares Pessoa
- Luís Eduardo Ramos Spinola
- Pablo dos Santos Martins

## Struct Musica

Atenção:
    
    Para a padronização dos dados do banco de dados o grupo optou por adotar a plataforma Youtube como fonte pricipal.



A struct música contém 7 "membros", sendo eles:

    string nome;
    string artista;
    string duracao;
    int ano;
    long long views;
    double media_views;
    string descricao;

#### STRING - nome:
Variável do tipo STRING, que guarda o nome/título da música, .
#### STRING - artista:
Variável do tipo STRING, que guarda o nome do artista, compositor ou cantor da respectova música.
#### STRING - duracao:
Variável do tipo STRING, que guarda a duração do principal vídeo da música no youtube no formato "X:XX", podendo ser representada por "XX:XX" no caso da música ter uma duração maior do que 9:59.
#### INT - ano:
Variável do tipo INT, que guarda o ano de postagem do respectivo vídeo do youtube (ano de lançamento no youtube).
#### LONG LONG - views:
Variável do tipo LONG LONG (anteriormente INT), que guarda o numero de vizualizações até o momento de adição da musica ao banco de dados.
    
    Após criar o sistema de leitura e impressão do banco de dados, o grupo notou que apartir de uma certa linha, não estava havendo a leitura correta dos dados, mais especificamente após a musica "Hello" que tem 3.231.637.278 vizualizações.

    Nisso, depois de uma pesquisa e revisão das anotações das aulas do Durelli, o grupo chegou a conclusão de que o número 3.231.637.278 não cabe em um int de 32 bits, porque o máximo que ele suporta é 2.147.483.647, por isso o código simplesmente dava overflow e lia incorretamente o restante dos dados.

    Assim, para armazenar esse valor corretamente, foi preciso usar um unsigned int, que vai de 0 a 4.294.967.295, ou um long long, que comporta números muito maiores do que o público de praticamente qualquer musica genérica do Youtube.

#### DOUBLE - media_views:
Variável do tipo DOUBLE, que guarda o numero de vizualizações dividida pelo tempo(em anos) de lançamento da música. 

    Para evitar conflito ou imprecisões nos cálculos as músicas com menos de 1 ano de lançamento recebem o próprio número de views como média.

#### STRING - descricao:
Variável do tipo STRING, que guarda a parte da música favorita da pessoa que adicionou, por preferência, pede-se que ao adicionar uma música, substritua-se as quebras de linha por ';' ao adicionar a musica ao banco de dados.

    No caso da musica ser instrumental o campo deve ser preenchido como: " " [Aspas com um espaço no meio]

## Funções primárias 
Funções primárias são aquelas chamadas diretamente na função principal, são um total de X funções, excluindo as funções-texto.

### Leitura_csv():

    Musica* Leitura_csv(Musica *musica, string nome_arquivo, int &capacidade, int &numero_de_musicas)


Essa função retorna um ponteiro da struct _Musica_ e tem como parâmetros um ponteiro dessa mesma struct, uma string com o nome do arquivo para a leitura, a capacidade total do vetor musica, e o numero total de musicas lidas (inicialmente zero). 

Os parâmetros de capacidade e do número de músicas são passados por referência.

O objetivo dessa função é a leitura integral do banco de dados _banco\_de\_dados.csv_ para a manipulação do usuário enquanto usa o programa.

A leitura ocorre respeitando o seguinte formato:

    "NomeDaMusica","NomeDoArtista","TempoDeDuração",AnoDeLançamento,NúmeroDeVisualizações,MédiaDeVisualizações,"TrechoMaisTocado"

A função usa o recurso _while()_ com a condição de que se houver algo no início da linha para se receber (Aspas no caso) quer dizer que existem informações a serem lidas na linha, então é utilzado o _getline()_ tendo as aspas do final da string como limitante.

Então, com a variavel de descarte _lixo_ lemos a vírgula e as aspas da próxima string. O ciclo se repete até a leitura do ano de nascimento.

    getline(entrada_csv, musica[i].nome, '\"');
    entrada_csv >> lixo;

    entrada_csv >> lixo;
    getline(entrada_csv, musica[i].artista, '\"');
    entrada_csv >> lixo;

Na leitura de variáveis sem aspas utilizamos simplesmente o operador _>>_ para atribuir a varável desejada ao seu respectivo campo, sempre lembrando de descartar as vírgulas.

    entrada_csv >> musica[i].ano >> lixo;

Assim, depois de ler a linha por completo o código se reinicia lendo linha após linha e realizando a contagem de músicas e conferindo se é necessário um redimensionamento do espaço de memória utilizado para a leitura.

### Exibe_banco_de_dados():

    void Exibe_banco_de_dados(Musica* &musica, int posicao_inicial, int posicao_final)

Esta função tem como objetivo exibir na tela os detalhes das músicas contidas no vetor de struct _Musica*_ dentro do intervalo especificado, para que o usuário visualize os dados sem alterar o banco.

A exibição ocorre em um loop _for_ que percorre do índice posicao_inicial até posicao_final, garantindo que as posições digitadas pelo usuário (começando em 1) sejam corretamente convertidas para índices do vetor (que começa em 0).

Para cada música, são exibidos os campos:

    Nome da música
    Artista
    Duração
    Ano de lançamento
    Número de visualizações

A média de visualizações por ano é exibida com quatro casas decimais, usando fixed e setprecision(4); 
(Da biblioteca \<iomanip>)

Em seguida, é exibida a parte mais reproduzida da música, chamando a função _imprime_formatado()_ para garantir a margem e a formatação correta do texto.

Ao final de cada música, a função insere uma quebra de linha e chama a função-texto _Linha()_ para separar visualmente cada registro, o que contribui para a interface do programa.

### BuscaPorNome():

    void BuscaPorNome(Musica *musica, int capacidade)

Esta função tem como objetivo permitir que o usuário busque músicas pelo nome dentro do vetor de struct Musica e visualize os detalhes das músicas que correspondem ao trecho digitado.

A função inicia descartando qualquer caractere residual no buffer de entrada com _cin.ignore()_ (da biblioteca \<iostream>) e solicita que o usuário digite o trecho a ser buscado, usando a função _Enunciados()_ para exibir a mensagem:

    "Insira o nome ou um trecho do nome da música: "

O trecho digitado é lido com _getline()_ e, em seguida, normalizado com as funções _Minusculo()_ e _Remover_acentos()_, garantindo que a busca seja case-insensitive e ignore acentos.

Um loop for percorre todo o vetor de músicas, convertendo o nome de cada música para minúsculas e removendo acentos para análise da mesma forma. A função _Achar_posicao()_ é utilizada para verificar se o trecho buscado está presente no nome da música.

Se houver correspondência, a variável achou é marcada como true e os detalhes da música são exibidos na tela, incluindo:

- Nome da música
- Artista
- Duração
- Ano de lançamento
- Número de visualizações

Média de visualizações por ano com quatro casas decimais, usando _fixed_ e _setprecision()_ (Da biblioteca\<iomanip>)

Em seguida, a parte mais reproduzida da música é exibida chamando a função _imprime_formatado()_ para manter a formatação correta do texto. A função _Linha()_ é chamada após cada música para separar visualmente os registros.

Ao final, se nenhuma música corresponder ao trecho buscado, é exibida a mensagem de erro:

    "Nenhuma música encontrada com esse nome."

### BuscaPorArtista():

    void BuscaPorArtista(Musica *musica, int capacidade)

Esta função tem como objetivo permitir que o usuário busque músicas pelo nome do artista dentro do vetor de struct _Musica_ e visualize os detalhes das músicas que correspondem ao trecho digitado.

A função inicia descartando qualquer caractere residual no buffer de entrada com _cin.ignore()_ (da biblioteca /<iostream>) e solicita que o usuário digite o trecho a ser buscado, usando a função _Enunciados()_ para exibir a mensagem:

    "Insira o nome ou um trecho do nome do artista: "

O trecho digitado é lido com _getline()_ e, em seguida, normalizado com as funções _Minusculo()_ e _Remover_acentos()_, garantindo que a busca seja case-insensitive e ignore acentos.

Um loop for percorre todo o vetor de músicas, convertendo o nome do artista de cada música para minúsculas e removendo acentos da mesma forma. A função _Achar_posicao()_ é utilizada para verificar se o trecho buscado está presente no nome do artista.

Se houver correspondência, a variável achou é marcada como true e os detalhes da música são exibidos na tela, incluindo:

- Nome da música
- Artista
- Duração
- Ano de lançamento
- Número de visualizações

A média de visualizações por ano é exibida com quatro casas decimais, usando fixed e setprecision() (da biblioteca \<iomanip>).

Em seguida, a parte mais reproduzida da música é exibida chamando a função _Imprime_formatado()_ para manter a formatação correta do texto. A função _Linha()_ é chamada após cada música para separar visualmente os registros.

Ao final, se nenhuma música corresponder ao trecho buscado, é exibida a mensagem de erro:

    "Nenhuma música encontrada desse artista."

### BuscaPorParte():

    void BuscaPorParte(Musica *musica, int capacidade)

Esta função tem como objetivo permitir que o usuário busque músicas pelo trecho mais reproduzido dentro do vetor de struct Musica e visualize os detalhes das músicas que contêm esse trecho.

A função inicia descartando qualquer caractere residual no buffer de entrada com _cin.ignore()_ (da biblioteca \<iostream>) e solicita que o usuário digite o trecho a ser buscado, usando a função _Enunciados()_ para exibir a mensagem:

    "Insira o trecho da música que deseja buscar: "

O trecho digitado é lido com _getline()_ e, em seguida, normalizado com as funções _Minusculo()_ e _Remover_acentos()_, garantindo que a busca seja case-insensitive e ignore acentos.

Um loop for percorre todo o vetor de músicas, convertendo o campo descricao de cada música para minúsculas e removendo acentos da mesma forma. A função _Achar_posicao()_ é utilizada para verificar se o trecho buscado está presente na parte mais reproduzida da música.

Se houver correspondência, a variável _achou_ é marcada como true e os detalhes da música são exibidos na tela, incluindo:

- Nome da música
- Artista
- Duração
- Ano de lançamento
- Número de visualizações

A média de visualizações por ano é exibida com quatro casas decimais, usando _fixed_ e _setprecision()_ (da biblioteca \<iomanip>).

Em seguida, a parte mais reproduzida da música é exibida chamando a função _Imprime_formatado()_ para manter a formatação correta do texto. A função _Linha()_ é chamada após cada música para separar visualmente os registros.

Ao final, se nenhuma música contiver o trecho buscado, é exibida a mensagem de erro:

    "Nenhuma música encontrada contém esse trecho."

### Ordena_os_indices():

    void Ordena_os_indices(int &indice1, int &indice2)

Esta função tem como objetivo garantir que dois valores inteiros fornecidos como parâmetros fiquem ordenados em ordem crescente com o objetivo de usar a função _Exibe_banco_de_dados()_ sem problemas. Assim, os parâmetros indice1 e indice2 são passados por referência.

A função compara os dois valores e, se indice1 for maior que indice2, realiza a troca de valores utilizando uma variável auxiliar auxiliar. Dessa forma, ao final da execução, indice1 sempre conterá o menor valor e indice2 o maior.

### Ordem_alfabetica_nome():

    void Ordem_alfabetica_nome(Musica* &musicas, int tamanho)

Esta função tem como objetivo ordenar o vetor de struct _Musica_ em ordem alfabética pelo nome da música, permitindo que o usuário visualize ou manipule o banco de dados de forma organizada.

O parâmetro _musicas_ é um ponteiro passado por referência, garantindo que as alterações feitas dentro da função modifiquem diretamente o vetor original. O parâmetro _tamanho_ indica a quantidade de músicas presentes no vetor.

A função utiliza o método de ordenação por inserção (insertion sort), percorrendo o vetor a partir do segundo elemento e comparando cada música com os elementos anteriores. Para a comparação, os nomes das músicas são convertidos para minúsculas usando a função _Minusculo()_, garantindo que a ordenação seja case-insensitive.

    INSERTION SORT:

    for(int i = 1; i < tamanho; i++){
        auxiliar = musicas[i];
        j = i - 1;
        while((j >= 0) and (Minusculo(musicas[j].nome) > Minusculo(auxiliar.nome))){
            musicas[j+1] = musicas[j];
            j--;
        }
        musicas[j+1] = auxiliar;
    }

Quando o nome da música atual é menor que os nomes anteriores, os elementos são deslocados para a direita e a música é inserida na posição correta. Dessa forma, ao final da execução, o vetor estará completamente ordenado alfabeticamente pelo nome das músicas.

### Ordem_visualizacoes():

    void Ordem_visualizacoes(Musica* &musicas, int tamanho)

Esta função tem como objetivo ordenar o vetor de struct _Musica_ em ordem decrescente pelo número de visualizações, permitindo que o usuário visualize ou manipule o banco de dados priorizando as músicas mais populares.

O parâmetro _musicas_ é um ponteiro passado por referência. O parâmetro _tamanho_ indica a quantidade de músicas presentes no vetor.

A função utiliza o método de ordenação por inserção (insertion sort), percorrendo o vetor a partir do segundo elemento e comparando cada música com os elementos anteriores. A comparação é feita diretamente pelo campo views de cada música, garantindo que as músicas com maior número de visualizações fiquem no início do vetor.

    INSERTION SORT:

    for(int i = 1; i < tamanho; i++){
        auxiliar = musicas[i];
        j = i - 1;
        while((j >= 0) and (musicas[j].views < auxiliar.views)){
            musicas[j+1] = musicas[j];
            j--;
        }
        musicas[j+1] = auxiliar;
    }

Quando o número de visualizações da música atual é maior que os das anteriores, os elementos são deslocados para a direita e a música é inserida na posição correta. Dessa forma, ao final da execução, o vetor estará completamente ordenado em ordem decrescente pelo número de visualizações.

### Ordem_media_visualizacoes():

    void Ordem_media_visualizacoes(Musica* &musicas, int tamanho)

Esta função tem como objetivo ordenar o vetor de struct _Musica_ em ordem decrescente pela média de visualizações por ano, permitindo que o usuário visualize ou manipule o banco de dados destacando as músicas com maior desempenho médio.

O parâmetro _musicas_ é um ponteiro passado por referência, garantindo que as alterações feitas dentro da função modifiquem diretamente o vetor original. O parâmetro _tamanho_ indica a quantidade de músicas presentes no vetor.

A função utiliza o método de ordenação por inserção (insertion sort), percorrendo o vetor a partir do segundo elemento e comparando cada música com os elementos anteriores. A comparação é feita diretamente pelo campo media_views de cada música, garantindo que as músicas com maior média de visualizações fiquem no início do vetor.

    INSERTION SORT:

    for(int i = 1; i < tamanho; i++){
        auxiliar = musicas[i];
        j = i - 1;
        while((j >= 0) and (musicas[j].media_views < auxiliar.media_views)){
            musicas[j+1] = musicas[j];
            j--;
        }
        musicas[j+1] = auxiliar;
    }

Quando a média de visualizações da música atual é maior que a das anteriores, os elementos são deslocados para a direita e a música é inserida na posição correta. Ao final da execução, o vetor estará completamente ordenado em ordem decrescente pela média de visualizações por ano.

### Salvar():

    void Salvar(Musica* musicas, int tamanho, string nome_arquivo)

Esta função tem como objetivo salvar o vetor de struct Musica em um arquivo CSV, permitindo que o banco de dados seja preservado e reutilizado em futuras execuções do programa.

O parâmetro _musicas_ é o vetor de músicas a ser salvo, _tamanho_ indica a quantidade de músicas presentes no vetor, e nome_arquivo é a string que define o nome do arquivo de saída.

A função utiliza um objeto _ofstream_ para abrir o arquivo especificado e grava cada música no formato CSV, respeitando a seguinte estrutura:

    "NomeDaMusica","NomeDoArtista","TempoDeDuração",AnoDeLançamento,NúmeroDeVisualizações,MédiaDeVisualizações,"TrechoMaisTocado"

Para garantir consistência na formatação da média de visualizações, a função utiliza _fixed_ e _setprecision()_ (da biblioteca \<iomanip>). Todos os campos de texto são delimitados por aspas, enquanto todos os campos, numéricos e de texto, são separados por vírgulas.

O loop _for()_ percorre todas as músicas do vetor, gravando linha a linha no arquivo de saída, permitindo que o banco de dados seja salvo de forma organizada e pronta para ser lida novamente com a função _Leitura_csv()_.

## Funções secundárias 
Funções secundárias são aquelas chamadas dentro de funções primárias, são um total de X funções, excluindo as funções-texto.

### Retira_acentos():

    string Retira_acentos(const string& str)

Esta função tem como objetivo remover acentos e caracteres especiais de uma string, substituindo-os por suas versões “simples” (por exemplo, á -> a e Ç -> C). 

O parâmetro _str_ é passado por referência constante (const string&), evitando cópias desnecessárias de memória. A função cria uma cópia da string (temp) que será modificada.

    MAPA:

    const map<string, string> MAPA_ACENTOS = {
        // Minúsculas
        {"á", "a"}, {"à", "a"}, {"ã", "a"}, {"â", "a"},
        {"é", "e"}, {"ê", "e"},
        {"í", "i"},
        {"ó", "o"}, {"õ", "o"}, {"ô", "o"},
        {"ú", "u"}, {"ü", "u"},
        {"ç", "c"},
        
        // Maiúsculas
        {"Á", "A"}, {"À", "A"}, {"Ã", "A"}, {"Â", "A"},
        {"É", "E"}, {"Ê", "E"},
        {"Í", "I"},
        {"Ó", "O"}, {"Õ", "O"}, {"Ô", "O"},
        {"Ú", "U"}, {"Ü", "U"},
        {"Ç", "C"}
    };

A função utiliza o mapa MAPA_ACENTOS (da biblioteca \<map>) que associa cada caractere acentuado à sua versão sem acento. Para cada par no mapa, a função:

1. Procura a posição do caractere acentuado na string usando _find()_ (da biblioteca \<string>).

2. Enquanto o caractere for encontrado (pos != string::npos), substitui-o com _replace()_.

Continua a busca a partir da posição seguinte para capturar múltiplas ocorrências.

Ao final, retorna a string normalizada, sem acentos, pronta para ser usada em comparações ou buscas.

### Redimensionamento():

    void Redimensionamento(Musica* &musica, int tamanho_anterior)

Esta função tem como objetivo aumentar a capacidade do vetor de struct Musica dinamicamente, permitindo que novas músicas sejam adicionadas sem perder os dados já armazenados.

O parâmetro _musica_ é um ponteiro passado por referência, garantindo que a alteração do vetor dentro da função seja refletida fora dela. O parâmetro _tamanho_anterior_ indica a quantidade de elementos atualmente armazenados no vetor.

A função cria um novo vetor de tamanho _tamanho_anterior_ + 5, copiando todos os elementos do vetor original para o novo vetor usando um loop _for()_. Após a cópia, o vetor original é liberado da memória com delete[], e o ponteiro _musica_ é atualizado para apontar para o novo vetor, que agora possui espaço maior para armazenar mais músicas.

Dessa forma, a função é continuamente utilizada pela função Leitura_csv() para que o tamanho do parâmetro _musica_ se adeque ao banco de dados.

### Imprime_formatado():

    void Imprime_formatado(const string &texto)

Esta função foi uma das mais desafiadoras para o grupo desenvolver, pois seu objetivo vai além de simplesmente exibir texto: ela precisa formatar o conteúdo de uma string para que cada linha não ultrapasse o limite de caracteres.

O parâmetro _texto_ é passado por referência constante, permitindo que a função leia o conteúdo sem alterá-lo e evitando cópias desnecessárias de memória.

A função define uma constante LIMITE = 47 que determina o número máximo de caracteres por linha. Em seguida, utiliza um loop while para percorrer toda a string, imprimindo segmentos de _texto_ respeitando o limite e evitando quebrar palavras no meio. A biblioteca \<iostream> é utilizada para cout.

#### Lógica principal:

1. Calcula a posição final do segmento (fim = pos + LIMITE).

2. 
    1. Se o segmento vai até o fim do texto, imprime o restante e encerra o loop (controle = false).
    
    2. Se há espaço exatamente na posição de quebra, imprime os próximos LIMITE caracteres e ajusta a posição inicial (pos).

    3. Se não houver espaço no limite, retrocede até encontrar o último espaço antes do limite para evitar quebrar palavras.

3. Imprime o segmento do texto usando substr(pos, tamanho) e atualiza a posição inicial (pos = quebra), ignorando espaços extras antes de iniciar o próximo segmento.
    
        Cada linha impressa começa com três espaços de recuo "\n" para manter a formatação visual uniforme.

O grupo enfrentou dificuldade principalmente ao lidar com quebras de linha sem cortar palavras, exigindo o uso de _substr()_, condicionais e loops para controlar cada caractere e espaço da string.

Biblioteca extra usada:

    <string> => string, size(), substr()

### Minusculo():

    string Minusculo(string s)

Esta função converte todos os caracteres de uma string para letras minúsculas, tornando comparações de texto case-insensitive.

Ela percorre cada caractere da string usando um loop _for()_ e, se o caractere estiver entre 'A' e 'Z', adiciona 32 para transformá-lo na letra minúscula correspondente (baseado na tabela ASCII).

Ao final, retorna a string modificada.


### Achar_posicao():

    bool Achar_posicao(string texto, string trecho)

Esta função tem como objetivo verificar se um _trecho_ de _texto_ está contido dentro de uma string maior, retornando true se o _trecho_ for encontrado e false caso contrário.

Ela utiliza o método _find()_ da classe string (da biblioteca \<string>) para procurar o _trecho_. Como _find()_ retorna a posição do _trecho_ ou string::npos se não encontrado, a função compara o valor retornado com _texto.size()_ para determinar a presença do _trecho_.

Essa função é amplamente utilizada nas funções de busca, como _BuscaPorNome()_, _BuscaPorArtista()_ e _BuscaPorParte()_, garantindo que a pesquisa funcione corretamente independentemente da posição do _trecho_ na string.

Bibliotecas usadas:

    <string> => string, find(), size()

