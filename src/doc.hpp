#ifndef DOC_HPP_INCLUDED
#define DOC_HPP_INCLUDED

/** \mainpage Steam Runner est une jeu de type rogue like steam punk post apocalyptique.
*       Un rogue like est un jeu proposant des parties plus ou moins courtes, appel�es rush, au cours desquelles on dirige un personnage � travers une s�rie de niveaux. A la fin d�un rush, le
*   personnage est supprim� et on recommence tout depuis le d�but lors d�un nouveau rush. Le but est donc g�n�ralement d�arriver le plus loin possible ou de faire le meilleur score au fil des rush.
*   L'int�r�t de ce type de jeu r�side dans le cot� al�atoire qui doit �tre tr�s pr�sent pour permettre une grande vari�t� de rush.
*       Steam punk est un terme utilis� pour d�signer un style d�univers �r�trofuturiste�, dont l'action se d�roule dans l'atmosph�re de la soci�t� industrielle du XIXe si�cle. Le terme fait
*   r�f�rence � l'utilisation massive des machines � vapeur au d�but de la r�volution industrielle puis � l'�poque victorienne, avec des composants contemporains comme la robotique, la
*   connaissance scientifique avanc�e.
*       Post apocalytpique est un terme utilis� pour d�signer un style d�univers o� l'humanit� se retrouve au bord de l�extinction suite � une catastrophe mondiale (g�n�ralement de type guerre
*   atomique ou ph�nom�ne inexpliqu�).
*       Notre jeu est donc un rogue like dont l�action se d�roule dans un univers o� l'humanit� a presque disparue, et o� la vapeur est la source d'�nergie commun�ment utilis�e, notamment
*   dans une robotique proche des inventions les plus farfelus de Leonard de Vinci.
*
* \section Features :
*       Une grande rejouabilit� : La rejouabilit�, pour un jeu vid�o, d�signe l�int�r�t pour le joueur de recommencer une partie. Il faut donc que le jeu contienne beaucoup
*    d��l�ments al�atoires, comme la g�n�ration du h�ros, des ennemis, et des niveaux, pour permettre au jeu de se renouveler. Un rush sera
*    toujours diff�rent du pr�c�dent. Il sera donc compos� d�une s�rie de salles, qui contiennent un ennemi ou un �v�nement al�atoire.
*        Un sc�nario : Le jeu doit comporter un sc�nario qui s�inscrit dans l�univers invent�. Ce sc�nario sera d�crit au cours du jeu. Le joueur doit avoir envie de continuer
*    � jouer non seulement parce que le jeu est amusant mais aussi pour d�couvrir le monde et l�histoire du h�ros. Le rush doit donc
*    contenir des salles obligatoires pour faire avancer l�histoire. Le sc�nario doit avoir une fin alternative (voir les autres features).
*        Une difficult� choisie : La difficult� doit pouvoir �tre choisie par le joueur au d�but de chaque rush pour lui permettre de jouer comme bon lui semble.
*    Plus la difficult� est �lev�e, plus les r�compenses sont �lev�es. Les r�compenses sont sous forme d�or utilis� pour am�liorer de fa�on persistante
*    son h�ros (voir �De la persistance entre les rush�). De plus, seule la difficult� maximum permet de d�couvrir la fin alternative du jeu.
*        De la persistance entre les rush : Le joueur doit pouvoir perfectionner son personnage avec des am�liorations persistantes
*    entre les rush. C�est � dire que le joueur recommence, certes depuis le d�but avec un nouveau h�ros � chaque nouveau rush, mais gr�ce � ces am�liorations, le joueur progresse en
*    puissance de rush en rush. Cela lui permet de faire des rush plus facilement ou d�augmenter la difficult� jusqu'� pouvoir survivre en difficult� maximale et d�couvrir la fin alternative du jeu.
*    Cependant, pour permettre � tous les joueurs, y compris les moins bons, de pouvoir acc�der � cette fin alternative, celle-ci.
*    est aussi visible � partir du moment o� toutes les am�liorations persistantes ont �t� d�bloqu�es (ce qui implique un certain temps de jeu).
*        Des combats en tour par tour et de la gestion de ressources : Lorsque le joueur rencontre un ennemi dans une salle, un combat s�engage. Le joueur
*    gagne de la pression � chaque tour, jusqu�� atteindre un niveau de pression maximum. Chaque action d�pense de la pression. Le joueur peut programmer jusqu�� cinq actions � chaque tour.
*    Le h�ros est compos� de cinq parties (t�te, torse, jambes, bras droit, bras gauche). Une action est une combinaison d�une de ces parties et d�une direction (haut, bas, gauche, droite). Par
*    exemple, si le joueur programme Jambes Droite, il se d�place � droite, ou encore Jambes Haut, il saute. Le joueur et l�ennemi se d�placent le long d�une ligne de cases donc sur un seul
*    axe. Toute la pression utilis�e pendant un combat sera d�duite de la r�serve de vapeur du h�ros  � la fin du combat, s�il est toujours vivant. Il faudra donc que le joueur utilise judicieusement ses
*    actions afin de ne pas manquer de vapeur. Sinon il sera oblig� de convertir son or gagn� jusqu�ici en vapeur. Et s�il vient � manquer d�or et de vapeur, le rush se termine tout simplement.
*        Des graphiques simples mais efficaces et une interface claire et d�taill�e : Les graphiques doivent �tre simples mais efficaces pour ne pas passer trop de temps �
*    les r�aliser. Ils pourront faire l�objet d'am�liorations si le temps et les ressources le permettent. L�interface doit �tre claire et d�taill�e pour permettre au joueur de bien comprendre les
*    m�canismes du jeu. Par exemple, au d�but d�un rush, apr�s la g�n�ration al�atoire du h�ros, le joueur peut choisir certaines parties de son h�ros pour les red�terminer
*    de mani�re al�atoire. Il faut donc qu�il puisse comprendre et savoir pr�cis�ment ce que lui apporte chaque partie et ainsi pouvoir agir en combat de mani�re r�fl�chie.
*
* \section Id�e originale de Pierre CASATI et Damien CLARAS.
*/


#endif // DOC_HPP_INCLUDED
