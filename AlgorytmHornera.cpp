// AlgorytmHornera.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>

//x^4-6x^3-11x^2-60x+100

int horner(int wsp[], int st, int x)
{
	if (st == 0)
		return wsp[0];

	return x * horner(wsp, st - 1, x) + wsp[st];
}

int main()
{
	std::string wielomian;
	std::string tmp, xtmp;
	int stmp;
	int stopien;
	char znaki[10];
	bool miany[9];
	int x, p = 0, m = 0, b = 0, j = 0, z = 0;
check:	
	std::cout << "Podaj wielomian (potega znaczkiem ^ np x^2): ";
	std::cin >> wielomian;

	for (int i = 0; i < wielomian.length(); i++) {
		if (i == 0) {
			if (wielomian[i] == ' ') {
				miany[b] = false;
				b++;
			}
			if (isdigit(wielomian[i])) {
				while (isdigit(wielomian[i + 1])) {
					i++;
				}
				if (wielomian[i + 1] == 'X' || wielomian[i + 1] == 'x') {
					if (wielomian[i + 2] == '^') {
						if (isdigit(wielomian[i + 3])) {
							miany[b] = true;
							b++;

						}
						else {
							miany[b] = false;
							b++;

						}
					}
					else {
						if (wielomian[i + 2] == '+' || wielomian[i + 2] == '-') {
							miany[b] = true;
							b++;

						}
						else {
							miany[b] = false;
							b++;

						}
					}
				}
				else {
					miany[b] = false;
					b++;

				}
			}
			else {
				if (wielomian[i] == 'X' || wielomian[i] == 'x') {
					if (wielomian[i + 1] == '^') {
						if (isdigit(wielomian[i + 2])) {
							miany[b] = true;
							b++;
						}
						else {
							miany[b] = false;
							b++;
						}
					}
					else {
						if (wielomian[i + 1] == '+' || wielomian[i + 1] == '-') {
							miany[b] = true;
							b++;
						}
						else {
							miany[b] = false;
							b++;
						}
					}
				}
				else {
					miany[b] = false;
					b++;
				}
			}
		}
		else {
			if (wielomian[i] == '+' || wielomian[i] == '-') {
				if (isdigit(wielomian[i + 1])) {
					while (isdigit(wielomian[i + 2])) {
						i++;
					}
					if (wielomian[i + 2] == 'X' || wielomian[i + 2] == 'x') {
						if (wielomian[i + 3] == '^') {
							if (isdigit(wielomian[i + 4])) {
								while (isdigit(wielomian[i + 5])) {
									i++;
								}
								miany[b] = true;
								b++;
							}
							else {
								miany[b] = false;
								b++;

							}
						}
						else {
							if (wielomian[i + 3] == '+' || wielomian[i + 3] == '-') {
								miany[b] = true;
								b++;

							}
							else {
								miany[b] = false;
								b++;

							}
						}
					}
					else {
						if (i + 2 != wielomian.length()) {
							miany[b] = false;
							b++;
						}
						else {
							miany[b] = true;
							b++;
						}
					}
				}
				else {
					if (i + 1 != wielomian.length()) {
						if (wielomian[i + 1] == 'X' || wielomian[i + 1] == 'x') {
							if (wielomian[i + 2] == '^') {
								if (isdigit(wielomian[i + 3])) {
									while (isdigit(wielomian[i + 4])) {
										i++;
									}
									miany[b] = true;
									b++;

								}
								else {
									miany[b] = false;
									b++;

								}
							}
							else {
								if (wielomian[i + 2] == '+' || wielomian[i + 2] == '-') {
									miany[b] = true;
									b++;

								}
								else {
									miany[b] = false;
									b++;

								}
							}
						}
						else {
							miany[b] = false;
							b++;

						}
					}
				}

			}
		}
	}

	for (int i = 0; i < 9; i++) {
		if (miany[i] == false) {
			std::cout << "Mian numer " << i + 1 << " podany z blendem !\n";
			system("pause");
			system("cls");
			wielomian = "";
			p = 0, m = 0, b = 0, j = 0, z = 0;
			goto check;
		}
	}
argum:
	std::cout << "Podaj argument (x): ";
	std::cin >> xtmp;
	for (int i = 0; i < xtmp.length(); i++) {
		if (!isdigit(xtmp[i])) {
			std::cout << "Argument musi byc cyfra !\n";
			system("pause");
			system("cls");
			tmp = "";
			goto argum;
			break;
		}
		else {
			tmp += xtmp[i];
		}
	}
	
	x = std::stoi(tmp);

	for (int i = 0; i < wielomian.length(); i++) {
		if (i == 0) {
			if (wielomian[i] == 'X' && wielomian[i + 1] == '^' || wielomian[i] == 'x' && wielomian[i + 1] == '^') {
				stopien = std::stoi(&wielomian[i + 2]);
				stmp = std::stoi(&wielomian[i + 2]);
			}
			else {
				j = p;
				while (wielomian[j] != 'x') {
					j++;
				}
				if (wielomian[j] == 'X' && wielomian[j + 1] == '^' || wielomian[j] == 'x' && wielomian[j + 1] == '^') {
					stopien = std::stoi(&wielomian[j + 2]);
					stmp = std::stoi(&wielomian[j + 2]);
				}
			}
		}
		else {
			if (wielomian[i] == 'X' && wielomian[i + 1] == '^' || wielomian[i] == 'x' && wielomian[i + 1] == '^') {
				stmp = std::stoi(&wielomian[i + 2]);
			}
		}
		if (stmp > stopien) {
			stopien = stmp;
		}
	}

	int *mnozniki = new int[stopien+1];

	for (int i = 0; i < wielomian.length(); i++) {
		if (i == 0) {
			if (isdigit(wielomian[i])) {
				j = i;
				while (wielomian[j] != 'x') {
					if (isdigit(wielomian[j])) {
						tmp += wielomian[j];
					}
					j++;
				}
				mnozniki[m] = std::stoi(tmp);
				tmp = "";
				m++;
			}
			else {
				mnozniki[m] = 1;
				m++;
			}
		}
		else {
			if (wielomian[i] == '-' || wielomian[i] == '+') {
				znaki[z] = wielomian[i];
				z++;
				if (isdigit(wielomian[i + 1])) {
					while (wielomian[i] != 'x') {
						if (isdigit(wielomian[i])) {
							tmp += wielomian[i];
						}
						if (i + 1 == wielomian.length()) {
							break;
						}
						i++;
					}
					mnozniki[m] = std::stoi(tmp);
					m++;
					tmp = "";
				}
				else {
					mnozniki[m] = 1;
					m++;
				}
			}
		}
	}

	std::cout << "W (" << x << ") = " << horner(mnozniki, stopien, x) << std::endl;
	system("pause");
	delete[] mnozniki;
	return 0;
}