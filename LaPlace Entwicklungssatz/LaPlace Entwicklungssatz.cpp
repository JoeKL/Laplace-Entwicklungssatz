// LaPlace Entwicklungssatz.cpp

#include "pch.h"
#include <iostream>
#include "math.h"
#include "time.h"

double det_laplace(double* A, int ROWS, int COLS) {			//	Initialisierung über ein 1-Dimensionales Array
	if (ROWS != COLS) {										//	Abfrage ob NxN Matrix
		printf("ERROR: Übergabe Parameter muss NxN Matrix sein!");			
		return NULL; 															
	} 																		
	int N = ROWS;											// hierdurch ist Arbeiten mit nur noch einer Variable möglich

	if (N == 1) {
		return A[1];
	}
									
	if (N == 2) {
		return A[1] * A[4] - A[2] * A[3];
	}

	if (N == 3) {											// bei 3x3 wird die Sarus Methode ausgeführt, um die Geschwindigkeit der Funktion voranzutreiben
		return ( A[1] * A[5] * A[9] + A[2] * A[6] * A[7] + A[3] * A[4] * A[8] - A[7] * A[5] * A[3] - A[8] * A[6] * A[1] - A[9] * A[4] * A[2] );
	}														
																			
	double detFinal = 0;	
																			
	for (int i = 1; i <= N; i++) {							// Das eigentliche Herz der Funktion: Folgender Teil wird Nx ausgeführt (so oft, wie es Zeilen/Spalten gibt)																			
		double *B = new double[(N - 1)*(N - 1)];		    // Eine kleinere Matrix mit Dimension N-1 x N-1 wird erstellt um den nächsten rekursiven Funktionsaufruf zu vereinfachen
		int B_lauf = 1;										// eine Laufvariable die das Speichern an den richtigen Arraystellen ermöglicht
		int row_lauf = 1;									// Laufvariable um das Streichen der Spalten zu ermöglichen											
		for (int j = N + 1; j <= (N*N); j++) {				// ermöglicht das Streichen der ersten Zeile										
			if ( j !=  i+(N*(row_lauf)) ) {					// Fragt ab ob der aktuelle Wert teil einer gestrichenen Spalte ist
				B[B_lauf] = A[j];							// wenn nicht: Wert wird in Hilfsarray gespeichert
				B_lauf++;									// Laufvariable wird erhöht um Speichern im nächsten Arrayslot zu ermöglichen
			}												
			else {											
				row_lauf++;									// wenn doch: Laufvariable wird erhöht, da in dieser Zeile die Spalte schon erreicht wurde
			}																							
		}													
		detFinal += pow(-1,i-1)*A[i]*det_laplace(B, (N - 1), (N - 1));				// Zusammenzählen mit der Laplace Formel
	}														
		return detFinal;									// Returnwert
}																			

void main()
{
	//Laufzeit initialisierung
	int anfang;
	int ende;
	int rest;

	//3x3 Matrix initialisierung
	const int rows = 3;  
	const int cols = 3;
	double *A = new double[rows*cols];

	A[1] = 2;	A[2] = 5;	A[3] = 2;	//a  b  c
	A[4] = 3;	A[5] = -3;	A[6] = 1;	//d  e  f
	A[7] = 1;	A[8] = 4;	A[9] = -4;  //g  h  i

	//Laufzeittest Laplace 3x3
	printf("LaPlace 3x3 (1.000.000x): ");
	double temp1;

	anfang = clock();
	for (int i = 1; i <= 1000000; i++) {
		temp1 = det_laplace(&A[0], 3, 3);
	}
	ende = clock();
	rest = ende - anfang;
	printf("%i ms\n", rest);
	printf("Determinante (Laplace)= %f\n", temp1);
	printf("\n");




	//4x4 Matrix initialisierung
	const int rows1 = 4;
	const int cols1 = 4;
	double *B = new double[rows1*cols1];

	B[1] = 1;	B[2] = 2;	B[3] = 3;	B[4] = 4;
	B[5] = 2;	B[6] = 7;	B[7] = 7;	B[8] = 3;
	B[9] = 2;	B[10] = 5;	B[11] = 8;	B[12] = 3;
	B[13] = 3;	B[14] = 4;	B[15] = 11;	B[16] = 12;
	

	//Laufzeittest Laplace 4x4
	printf("LaPlace 4x4 (1.000.000x): ");
	double temp2;

	anfang = clock();
	for (int i = 1; i <= 1000000; i++) {
		temp2 = det_laplace(&B[0], 4, 4);
	}
	ende = clock();
	rest = ende - anfang;
	printf("%i ms\n", rest);
	printf("Determinante (Laplace) = %f\n", temp2);
	printf("\n");




	//5x5 Matrix initialisierung
	const int rows2 = 5;
	const int cols2 = 5;
	double *C = new double[rows2*cols2];

	C[1] = 1;	C[2] = 2;	C[3] = 3;	C[4] = 4;	C[5] = 2;
	C[6] = 7;	C[7] = 7;	C[8] = 3;	C[9] = 2;	C[10] = 5;
	C[11] = 8;	C[12] = 3;	C[13] = 3;	C[14] = 4;	C[15] = 11;
	C[16] = 5;	C[17] = 21;	C[18] = 1;	C[19] = 11;	C[20] = 8;
	C[21] = 20;	C[22] = 92;	C[23] = 7;	C[24] = 2;	C[25] = 20;


	//Laufzeittest Laplace 5x5
	printf("LaPlace 5x5 (100.000x): ");
	double temp3;

	anfang = clock();
	for (int i = 1; i <= 100000; i++) {
		temp3 = det_laplace(&C[0], 5, 5);
	}
	ende = clock();

	rest = ende - anfang;
	printf("%i ms\n", rest);
	printf("Determinante (Laplace) = %f\n", temp3);
	printf("\n");


	//5x5 Matrix initialisierung
	const int rows3 = 6;
	const int cols3 = 6;
	double *D = new double[rows3*cols3];

	D[1] = 1;	D[2] = 2;	D[3] = 3;	D[4] = 4;	D[5] = 2;   D[6] = 7;	
	D[7] = 7;	D[8] = 3;	D[9] = 2;	D[10] = 5;  D[11] = 8;  D[12] = 3;
	D[13] = 3;	D[14] = 4;	D[15] = 11; D[16] = 5;	D[17] = 21;	D[18] = 1;	
	D[19] = 11;	D[20] = 8;  D[21] = 20;	D[22] = 92;	D[23] = 7;	D[24] = 2;	
	D[25] = 2;  D[26] = -2; D[27] = 9;  D[28] = 4;  D[29] = 5;  D[30] = 11;
	D[31] = 0;  D[32] = 3;  D[33] = 11; D[34] = 2;  D[35] = 2;  D[36] = 1;


	//Laufzeittest Laplace 5x5
	printf("LaPlace 6x6 (10.000x): ");
	double temp4;

	anfang = clock();
	for (int i = 1; i <= 10000; i++) {
		temp4 = det_laplace(&D[0], 6, 6);
	}
	ende = clock();

	rest = ende - anfang;
	printf("%i ms\n", rest);
	printf("Determinante (Laplace) = %f\n", temp4);
	printf("\n");

	system("pause");
}