#include <iostream>

using namespace std;

float licz_impact(float rd, float kill, float ast)
{
	float apr = ast / rd;
	float kpr = kill / rd;

	return (2.130 * kpr) + (0.420 * apr) - 0.410;
}

float licz_rating(float rd, float kill, float ast, float dead, float puste, float adr, float impact)
{
	float apr = ast / rd;
	float kpr = kill / rd;
	float dpr = dead / rd;
	float kast = ((rd - puste) / rd) * 100;

	return 0.0073 * kast + 0.3591 * kpr + (-0.5329 * dpr) + 0.2372 * impact + 0.0032 * adr + 0.1587;
}

int main()
{
	float rd, kill, ast, puste, adr, dead;

	cout << "Podaj liczbe rund: ";
	cin >> rd;
	cout << "\nPodaj liczbe killi: ";
	cin >> kill;
	cout << "\nPodaj liczbe asyst: ";
	cin >> ast;
	cout << "\nPodaj liczbe smierci: ";
	cin >> dead;
	cout << "\nPodaj ADR: ";
	cin >> adr;
	cout << "\nPodaj liczbe rund bez killa, asysty, tradea: ";
	cin >> puste;

	float impact = licz_impact(rd, kill, ast);
	float rating = licz_rating(rd, kill, ast, dead, puste, adr, impact);

	cout << "\nTwoj rating 2.0: " << rating << " gratulacje!" << endl;

	return 0;
}