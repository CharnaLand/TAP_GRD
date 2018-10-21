Probleme Greedy - Tehnici avansate de TAP

#Partitionarea Intervalelor

Idee: sortare intervale dupa ora de incepere si durata in mod crescator 
apoi adaugare fiecare Interval intr-o Aranjare

Interval - o clasa pentru definirea unui interval
	+parametrii de inceput si de sfarsit
	+operator< - pentru a folosi sort-ului din algorithm
	+operator<= - pentru a verifica daca doua intervale se pot 
succede unul pe celalalt
	+operator+ - pentru a uni doua intervale intr-unul singur 
(inceputul primului cu sfarsitul celui de-al doilea)

AranJare - o clasa care retine intervale pe sali
	+nrSali si nrEvenimente
	+matrice 'repart' 
		*pe liniile 1->nrSali se retin intervalele pentru acea 
sala
		*pe linia 0 se retine intervalul in care fiecare sala  
este ocupata
	+operator+= - pentru a adauga un interval la aranjarea existenta
	+addInSalaNoua - creare sala noua pentru un interval
	+addInSala - adaugare un interval intr-o sala, daca acesta nu se 
suprapune 
