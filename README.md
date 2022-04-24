# Aferidor de Empuxo de Motores com o Arduino
Desenvolvimento de um aferidor de empuxo de motores com arduino // Projeto integrador I6-2022.1


1.Váriaveis: 
  - sck e dt, **int**: 
    - São as portas do HX711 
  - calibra, **float**: 
    - É o fator de calibração da balança
  - peso e newton, **float**:
    - Varíveis para auxilio do calculo
  - armz[x], **float**:
    - Varíavel temporaria de armenamento dos valores calculados
  - enc, tipo **bool**:
    - Varível logica para oa encerramento do programa
  - i e itemp, **int**:
    - Varíveis utilizadas nas estruturas de repetição

2.Funções utilizadas da biblioteca HX711: 
  - Necessário declara o HX711:
    - Para declarar: HX711 Variável
      - Ex: HX711 balanca
    - Essa variável vai ser utilizada em todo o projeto que for necessário o HX711 
   
  - **tara**()
    - Função para tarar
      - Ex: balanca.tara

  - **set_units**(N)
    - Realiza a leitura, sendo o N o número de leituras realizadas e trazido uma média.
      - Ex: balanca.set_units(10)

  - **begin**(DT, SCK) 
    - Inicia o HX711 declarando quais as portas
        - Ex: balanca.begin(3,2)
  
  - **set_scale**(Fator de calibração)
    - Seta o valor de calibração do HX711
      - Ex: balanca.set_scale(180000.00)

3.Funções utilizadas da biblioteca Arduino: 
  - X.**begin**(speed)
    - Função dado para iniciar o monitoramento, onde X seria o nome dado normalmente de Serial. O paremetro speed se refere a taxa de transmissão em bits por segundo, o padrão utilizado no projeto é o 9600.  
      - Ex: Serial.begin(9600);
       
  - X.**println**(Y)
    - Função para printar no serial especificado no X, onde ira printar o parametro Y;
      - Ex: Serial.println(newton);
         
  - **delay**(ms)
    - Pausa o programa por uma quantidade especificada de tempo (em milissegundos), 1000 = 1 segundo; 
      - Ex: daley(1000)
  
4.Funções desenvolvidas: 
  - **Calc**(float x)
    - Função retorna o valor da força newton que está sendo aplicada utilizando para calcular o valor da massa dada pelas celulas de carga e HX711;
  
  - **GravTemp**(float X)
    - Função recebe um valor e grava em um array temporário, além disso verifica se a aferidor está enviando vários numeros igual, onde se for verdadeiro irá devolver a referencias para encerrar o programa. 

  - **finish**()
    - Função que vai ser realizado a gravação dos resultados no sd card 

## Referencias:

Documentação do arduino: https://www.arduino.cc/reference/pt/

Documentação do HX711: https://github.com/bogde/HX711
