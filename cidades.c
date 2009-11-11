/*--------------------------------------------------Alunos
Felipe Vieira		08160913

Rafael Mardegan		xXxXxXxX

Paulo Cecilio		08110405
*/


/*--------------------------------------------------Referências*/
#include<string.h>


/*--------------------------------------------------Constantes*/
#define INF 0x3f3f3f3f

#define N 41

#define Albany 0
#define Aspen 1
#define Atlanta 2
#define Boise 3
#define Boston 4
#define Chicago 5
#define Colorado_Springs 6
#define Dallas 7
#define Denver 8
#define Detroit 9
#define Fort_Lauderdale 10
#define Grand_Cannon 11
#define Houston 12
#define Indianapolis 13
#define Kansas_City 14
#define Lake_Tohoe 15
#define Las_Vegas 16
#define Little_Rock 17
#define Los_Angeles 18
#define Memphis 19
#define Miami 20
#define Milwaukee 21
#define Minneapolis 22
#define Nashville 23
#define Nova_Orleans 24
#define Nova_York 25
#define Omaha 26
#define Orlando 27
#define Palm_Springs 28
#define Phoenix 29
#define Portland 30
#define Richmond 31
#define Salt_Lake_City 32
#define San_Antonio 33
#define San_Diego 34
#define San_Francisco 35
#define Seatle 36
#define St_louis 37
#define Vail 38
#define Washington 39
#define Yellowstone 40



/*--------------------------------------------------Variáveis Globais*/
int matrizAdjacencia[N][N];
char nomeCidades[N][50];


/*---------------------------------------------------Alimentar vetor com o nome das cidades*/
void preencheVetorNomeCidades() 
{
	strcpy(nomeCidades[Albany], "Albany");
	strcpy(nomeCidades[Aspen], "Aspen");
	strcpy(nomeCidades[Atlanta], "Atlanta");
	strcpy(nomeCidades[Boise], "Boise");
	strcpy(nomeCidades[Boston], "Boston");
	strcpy(nomeCidades[Chicago], "Chicago");
	strcpy(nomeCidades[Colorado_Springs], "Colorado Springs");
	strcpy(nomeCidades[Dallas], "Dallas");
	strcpy(nomeCidades[Denver], "Denver");
	strcpy(nomeCidades[Detroit], "Detroit");
	strcpy(nomeCidades[Fort_Lauderdale], "Fort Lauderdale");
	strcpy(nomeCidades[Grand_Cannon], "Grand Cannon");
	strcpy(nomeCidades[Houston], "Houston");
	strcpy(nomeCidades[Indianapolis], "Indianapolis");
	strcpy(nomeCidades[Kansas_City], "Kansas City");
	strcpy(nomeCidades[Lake_Tohoe], "Lake Tohoe");
	strcpy(nomeCidades[Las_Vegas], "Las Vegas");
	strcpy(nomeCidades[Little_Rock], "Little Rock");
	strcpy(nomeCidades[Los_Angeles], "Los Angeles");
	strcpy(nomeCidades[Memphis], "Memphis");
	strcpy(nomeCidades[Miami], "Miami");
	strcpy(nomeCidades[Milwaukee], "Milwaukee");
	strcpy(nomeCidades[Minneapolis], "Minneapolis");
	strcpy(nomeCidades[Nashville], "Nashville");
	strcpy(nomeCidades[Nova_Orleans], "Nova Orleans");
	strcpy(nomeCidades[Nova_York], "Nova York");
	strcpy(nomeCidades[Omaha], "Omaha");
	strcpy(nomeCidades[Orlando], "Orlando");
	strcpy(nomeCidades[Palm_Springs], "Palm Springs");
	strcpy(nomeCidades[Phoenix], "Phoenix");
	strcpy(nomeCidades[Portland], "Portland");
	strcpy(nomeCidades[Richmond], "Richmond");
	strcpy(nomeCidades[Salt_Lake_City], "Salt Lake City");
	strcpy(nomeCidades[San_Antonio], "San Antonio");
	strcpy(nomeCidades[San_Diego], "San Diego");
	strcpy(nomeCidades[San_Francisco], "San Francisco");
	strcpy(nomeCidades[Seatle], "Seatle");
	strcpy(nomeCidades[St_louis], "St louis");
	strcpy(nomeCidades[Vail], "Vail");
	strcpy(nomeCidades[Washington], "Washington");
	strcpy(nomeCidades[Yellowstone], "Yellowstone");

}


/*---------------------------------------------------Alimentar matriz com os trajetos entre as cidades adjacentes*/
void preencherMatrizAdjacencia()
{
	matrizAdjacencia[Albany][Boston] = 17;
	matrizAdjacencia[Albany][Detroit] = 65;
	matrizAdjacencia[Albany][Nova_York] = 15;

	matrizAdjacencia[Aspen][Colorado_Springs] = 18;
	matrizAdjacencia[Aspen][Denver] = 17;
	matrizAdjacencia[Aspen][Vail] = 8;

	matrizAdjacencia[Atlanta][Dallas] = 79;
	matrizAdjacencia[Atlanta][Memphis] = 39;
	matrizAdjacencia[Atlanta][Nashville] = 24;
	matrizAdjacencia[Atlanta][Nova_Orleans] = 47;
	matrizAdjacencia[Atlanta][Orlando] = 44;
	matrizAdjacencia[Atlanta][Richmond] = 56;

	matrizAdjacencia[Boise][Lake_Tohoe] = 42;
	matrizAdjacencia[Boise][Portland] = 42;
	matrizAdjacencia[Boise][Seatle] = 50;
	matrizAdjacencia[Boise][Yellowstone] = 67;

	matrizAdjacencia[Boston][Albany] = 17;
	matrizAdjacencia[Boston][Nova_York] = 21;

	matrizAdjacencia[Chicago][Detroit] = 28;
	matrizAdjacencia[Chicago][Indianapolis] = 18;
	matrizAdjacencia[Chicago][Milwaukee] = 9;
	matrizAdjacencia[Chicago][Minneapolis] = 41;
	matrizAdjacencia[Chicago][Omaha] = 47;
	matrizAdjacencia[Chicago][St_louis] = 30;
	matrizAdjacencia[Chicago][Washington] = 70;

	matrizAdjacencia[Colorado_Springs][Aspen] = 18;
	matrizAdjacencia[Colorado_Springs][Dallas] = 73;
	matrizAdjacencia[Colorado_Springs][Denver] = 12;

	matrizAdjacencia[Dallas][Atlanta] = 79;
	matrizAdjacencia[Dallas][Colorado_Springs] = 73;
	matrizAdjacencia[Dallas][Houston] = 25;
	matrizAdjacencia[Dallas][Kansas_City] = 55;
	matrizAdjacencia[Dallas][Little_Rock] = 32;
	matrizAdjacencia[Dallas][Phoenix] = 107;
	matrizAdjacencia[Dallas][San_Antonio] = 28;

	matrizAdjacencia[Denver][Aspen] = 17;
	matrizAdjacencia[Denver][Colorado_Springs] = 12;
	matrizAdjacencia[Denver][Omaha] = 54;
	matrizAdjacencia[Denver][Salt_Lake_City] = 53;
	matrizAdjacencia[Denver][Vail] = 17;
	matrizAdjacencia[Denver][Yellowstone] = 93;

	matrizAdjacencia[Detroit][Albany] = 65;
	matrizAdjacencia[Detroit][Chicago] = 28;
	matrizAdjacencia[Detroit][Nova_York] = 64;
	matrizAdjacencia[Detroit][Washington] = 53;

	matrizAdjacencia[Fort_Lauderdale][Miami] = 3;
	matrizAdjacencia[Fort_Lauderdale][Orlando] = 18;

	matrizAdjacencia[Grand_Cannon][Las_Vegas] = 47;
	matrizAdjacencia[Grand_Cannon][Palm_Springs] = 44;
	matrizAdjacencia[Grand_Cannon][Phoenix] = 36;

	matrizAdjacencia[Houston][Dallas] = 25;
	matrizAdjacencia[Houston][Nova_Orleans] = 53;
	matrizAdjacencia[Houston][San_Antonio] = 31;

	matrizAdjacencia[Indianapolis][Chicago] = 18;
	matrizAdjacencia[Indianapolis][Nashville] = 29;
	matrizAdjacencia[Indianapolis][St_louis] = 25;
	matrizAdjacencia[Indianapolis][Washington] = 59;

	matrizAdjacencia[Kansas_City][Dallas] = 55;
	matrizAdjacencia[Kansas_City][Omaha] = 19;
	matrizAdjacencia[Kansas_City][St_louis] = 25;

	matrizAdjacencia[Lake_Tohoe][Boise] = 42;
	matrizAdjacencia[Lake_Tohoe][Palm_Springs] = 78;
	matrizAdjacencia[Lake_Tohoe][Portland] = 58;
	matrizAdjacencia[Lake_Tohoe][Salt_Lake_City] = 52;
	matrizAdjacencia[Lake_Tohoe][San_Francisco] = 30;

	matrizAdjacencia[Las_Vegas][Grand_Cannon] = 47;
	matrizAdjacencia[Las_Vegas][Los_Angeles] = 27;
	matrizAdjacencia[Las_Vegas][Palm_Springs] = 29;
	matrizAdjacencia[Las_Vegas][Salt_Lake_City] = 42;

	matrizAdjacencia[Little_Rock][Dallas] = 32;
	matrizAdjacencia[Little_Rock][Memphis] = 14;
	matrizAdjacencia[Little_Rock][St_louis] = 40;

	matrizAdjacencia[Los_Angeles][Las_Vegas] = 27;
	matrizAdjacencia[Los_Angeles][Palm_Springs] = 16;
	matrizAdjacencia[Los_Angeles][San_Diego] = 12;
	matrizAdjacencia[Los_Angeles][San_Francisco] = 38;

	matrizAdjacencia[Memphis][Atlanta] = 39;
	matrizAdjacencia[Memphis][Little_Rock] = 14;
	matrizAdjacencia[Memphis][Nashville] = 21;
	matrizAdjacencia[Memphis][St_louis] = 29;

	matrizAdjacencia[Miami][Fort_Lauderdale] = 3;
	matrizAdjacencia[Miami][Nova_Orleans] = 86;
	matrizAdjacencia[Miami][Orlando] = 23;

	matrizAdjacencia[Milwaukee][Chicago] = 9;
	matrizAdjacencia[Milwaukee][Minneapolis] = 34;

	matrizAdjacencia[Minneapolis][Chicago] = 41;
	matrizAdjacencia[Minneapolis][Milwaukee] = 34;
	matrizAdjacencia[Minneapolis][Omaha] = 38;
	matrizAdjacencia[Minneapolis][Yellowstone] = 134;

	matrizAdjacencia[Nashville][Atlanta] = 24;
	matrizAdjacencia[Nashville][Indianapolis] = 29;
	matrizAdjacencia[Nashville][Memphis] = 21;
	matrizAdjacencia[Nashville][Richmond] = 71;

	matrizAdjacencia[Nova_Orleans][Atlanta] = 47;
	matrizAdjacencia[Nova_Orleans][Houston] = 53;
	matrizAdjacencia[Nova_Orleans][Miami] = 86;
	matrizAdjacencia[Nova_Orleans][Orlando] = 64;

	matrizAdjacencia[Nova_York][Albany] = 15;
	matrizAdjacencia[Nova_York][Boston] = 21;
	matrizAdjacencia[Nova_York][Detroit] = 64;
	matrizAdjacencia[Nova_York][Washington] = 24;

	matrizAdjacencia[Omaha][Chicago] = 47;
	matrizAdjacencia[Omaha][Denver] = 54;
	matrizAdjacencia[Omaha][Kansas_City] = 19;
	matrizAdjacencia[Omaha][Minneapolis] = 38;

	matrizAdjacencia[Orlando][Atlanta] = 44;
	matrizAdjacencia[Orlando][Fort_Lauderdale] = 18;
	matrizAdjacencia[Orlando][Miami] = 23;
	matrizAdjacencia[Orlando][Nova_Orleans] = 64;

	matrizAdjacencia[Palm_Springs][Grand_Cannon] = 44;
	matrizAdjacencia[Palm_Springs][Lake_Tohoe] = 78;
	matrizAdjacencia[Palm_Springs][Las_Vegas] = 29;
	matrizAdjacencia[Palm_Springs][Los_Angeles] = 16;
	matrizAdjacencia[Palm_Springs][San_Diego] = 14;

	matrizAdjacencia[Phoenix][Dallas] = 107;
	matrizAdjacencia[Phoenix][Grand_Cannon] = 36;
	matrizAdjacencia[Phoenix][Salt_Lake_City] = 66;
	matrizAdjacencia[Phoenix][San_Antonio] = 99;
	matrizAdjacencia[Phoenix][San_Diego] = 35;

	matrizAdjacencia[Portland][Boise] = 42;
	matrizAdjacencia[Portland][Lake_Tohoe] = 58;
	matrizAdjacencia[Portland][San_Francisco] = 64;
	matrizAdjacencia[Portland][Seatle] = 17;

	matrizAdjacencia[Richmond][Atlanta] = 42;
	matrizAdjacencia[Richmond][Nashville] = 71;
	matrizAdjacencia[Richmond][Washington] = 20;

	matrizAdjacencia[Salt_Lake_City][Denver] = 53;
	matrizAdjacencia[Salt_Lake_City][Lake_Tohoe] = 52;
	matrizAdjacencia[Salt_Lake_City][Las_Vegas] = 42;
	matrizAdjacencia[Salt_Lake_City][Phoenix] = 66;

	matrizAdjacencia[San_Antonio][Dallas] = 28;
	matrizAdjacencia[San_Antonio][Houston] = 31;
	matrizAdjacencia[San_Antonio][Phoenix] = 99;
	
	matrizAdjacencia[San_Diego][Los_Angeles] = 12;
	matrizAdjacencia[San_Diego][Phoenix] = 35;

	matrizAdjacencia[San_Francisco][Lake_Tohoe] = 30;
	matrizAdjacencia[San_Francisco][Los_Angeles] = 38;
	matrizAdjacencia[San_Francisco][Portland] = 64;

	matrizAdjacencia[Seatle][Boise] = 50;
	matrizAdjacencia[Seatle][Portland] = 17;

	matrizAdjacencia[St_louis][Chicago] = 30;
	matrizAdjacencia[St_louis][Indianapolis] = 25;
	matrizAdjacencia[St_louis][Kansas_City] = 25;
	matrizAdjacencia[St_louis][Little_Rock] = 40;
	matrizAdjacencia[St_louis][Memphis] = 29;

	matrizAdjacencia[Vail][Aspen] = 8;
	matrizAdjacencia[Vail][Denver] = 16;

	matrizAdjacencia[Washington][Chicago] = 70;
	matrizAdjacencia[Washington][Detroit] = 53;
	matrizAdjacencia[Washington][Indianapolis] = 59;
	matrizAdjacencia[Washington][Nova_York] = 24;
	matrizAdjacencia[Washington][Richmond] = 20;

	matrizAdjacencia[Yellowstone][Boise] = 67;
	matrizAdjacencia[Yellowstone][Denver] = 93;
	matrizAdjacencia[Yellowstone][Minneapolis] = 134;
}
