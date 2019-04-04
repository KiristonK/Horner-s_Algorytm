#include "pch.h"
#include <iostream>
#include <math.h>
#include <string>
#include <string.h>

//x^4-6x^3-11x^2-60x+100

long long int horner(int wsp[], int st, int x)
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
	bool mian;
	int x, p = 0, m = 0, j = 0;

check:	
	std::cout << "Podaj wielomian (potega znaczkiem ^ np x^2): ";
	std::cin >> wielomian;
//sprawdzanie wielomiana
	for (int i = 0; i < wielomian.length(); i++) {
		if (i == 0) {
			if (wielomian[i] == ' ') {
				mian = false;
				break;
			}
			if (isdigit(wielomian[i])) {
				while (isdigit(wielomian[i + 1])) {
					i++;
				}
				if (wielomian[i + 1] == 'X' || wielomian[i + 1] == 'x') {
					if (wielomian[i + 2] == '^') {
						if (isdigit(wielomian[i + 3])) {
							if (wielomian[i + 4] == '-' || wielomian[i + 4] == '+') {
								mian = true;
							}
							else {
								mian = false;
								break;
							}
						}
						else {
							mian = false;
							break;
						}
					}
					else {
						if (wielomian[i + 2] == '+' || wielomian[i + 2] == '-') {
							mian = true;

						}
						else {
							mian = false;
							break;
						}
					}
				}
				else {
					mian = false;
					break;
				}
			}
			else {
				if (wielomian[i] == 'X' || wielomian[i] == 'x') {
					if (wielomian[i + 1] == '^') {
						if (isdigit(wielomian[i + 2])) {
							if (wielomian[i + 3] == '-' || wielomian[i + 3] == '+') {
								mian = true;
							}
							else {
								mian = false;
								break;
							}
						}
						else {
							mian = false;
							break;
						}
					}
					else {
						if (wielomian[i + 1] == '+' || wielomian[i + 1] == '-') {
							mian = true;
						}
						else {
							mian = false;
							break;
						}
					}
				}
				else {
					mian = false;
					break;
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
								if (wielomian[i + 5] == '-' || wielomian[i + 5] == '+') {
									mian = true;
								}
								else {
									mian = false;
									break;
								}
							}
							else {
								mian = false;
								break;

							}
						}
						else {
							if (wielomian[i + 3] == '+' || wielomian[i + 3] == '-') {
								mian = true;
							}
							else {
								mian = false;
								break;
							}
						}
					}
					else {
						if (i + 2 != wielomian.length()) {
							mian = false;
							break;
						}
						else {
							mian = true;
						}
					}
				}
				else {
					if (i + 1 != wielomian.length()) {
						if (wielomian[i + 1] == 'X' || wielomian[i + 1] == 'x') {
							if (wielomian[i + 2] == '^') {
								if (isdigit(wielomian[i + 3])) {
									if (wielomian[i + 4] == '-' || wielomian[i + 4] == '+') {
										mian = true;
									}
									else {
										mian = false;
										break;
									}
								}
								else {
									mian = false;
									break;

								}
							}
							else {
								if (wielomian[i + 2] == '+' || wielomian[i + 2] == '-') {
									mian = true;
								}
								else {
									mian = false;
									break;

								}
							}
						}
						else {
							mian = false;
							break;

						}
					}
				}
			}
		}
	}

	
	if (mian == false) {
		std::cout << "Wielomian podany z blendem !\n";
		system("pause");
		system("cls");
		wielomian = "";
		p = 0, m = 0, j = 0;
		goto check;
	}
argum:
	std::cout << "Podaj argument (x): ";
	std::cin >> xtmp;
	for (int i = 0; i < xtmp.length(); i++) {
		if (!isdigit(xtmp[i])) {
			std::cout << "Argument musi byc cyfra !\n";
			system("pause");
			system("cls");
			std::cout << "Podaj wielomian (potega znaczkiem ^ np x^2): " << wielomian << std::endl;
			tmp = "";
			goto argum;
			break;
		}
		else {
			tmp += xtmp[i];
		}
	}
	x = std::stoi(tmp);
//stopien
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
//wspolczynniki
	for (int i = 0; i < wielomian.length(); i++) {
		if (i == 0) {
			if (isdigit(wielomian[i])) {
				tmp = "";
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
				if (isdigit(wielomian[i + 1])) {
					tmp = "";
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
	for (int i = 0; i < stopien + 1; i++) {
		if (mnozniki[i] <= 0) {
			mnozniki[i] = 1;
		}
	}

	std::cout << "W (" << x << ") = " << horner(mnozniki, stopien, x) << std::endl;
	system("pause");
	delete[] mnozniki;
	return 0;
}