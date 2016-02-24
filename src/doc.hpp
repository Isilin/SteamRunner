#ifndef DOC_HPP_INCLUDED
#define DOC_HPP_INCLUDED

/** \mainpage Steam Runner est une jeu de type rogue like steam punk post apocalyptique.
*       Un rogue like est un jeu proposant des parties plus ou moins courtes, appelées rush, au cours desquelles on dirige un personnage à travers une série de niveaux. A la fin d’un rush, le
*   personnage est supprimé et on recommence tout depuis le début lors d’un nouveau rush. Le but est donc généralement d’arriver le plus loin possible ou de faire le meilleur score au fil des rush.
*   L'intérêt de ce type de jeu réside dans le coté aléatoire qui doit être très présent pour permettre une grande variété de rush.
*       Steam punk est un terme utilisé pour désigner un style d’univers “rétrofuturiste”, dont l'action se déroule dans l'atmosphère de la société industrielle du XIXe siècle. Le terme fait
*   référence à l'utilisation massive des machines à vapeur au début de la révolution industrielle puis à l'époque victorienne, avec des composants contemporains comme la robotique, la
*   connaissance scientifique avancée.
*       Post apocalytpique est un terme utilisé pour désigner un style d’univers où l'humanité se retrouve au bord de l’extinction suite à une catastrophe mondiale (généralement de type guerre
*   atomique ou phénomène inexpliqué).
*       Notre jeu est donc un rogue like dont l’action se déroule dans un univers où l'humanité a presque disparue, et où la vapeur est la source d'énergie communément utilisée, notamment
*   dans une robotique proche des inventions les plus farfelus de Leonard de Vinci.
*
* \section Features :
*       Une grande rejouabilité : La rejouabilité, pour un jeu vidéo, désigne l’intérêt pour le joueur de recommencer une partie. Il faut donc que le jeu contienne beaucoup
*    d’éléments aléatoires, comme la génération du héros, des ennemis, et des niveaux, pour permettre au jeu de se renouveler. Un rush sera
*    toujours différent du précédent. Il sera donc composé d’une série de salles, qui contiennent un ennemi ou un événement aléatoire.
*        Un scénario : Le jeu doit comporter un scénario qui s’inscrit dans l’univers inventé. Ce scénario sera décrit au cours du jeu. Le joueur doit avoir envie de continuer
*    à jouer non seulement parce que le jeu est amusant mais aussi pour découvrir le monde et l’histoire du héros. Le rush doit donc
*    contenir des salles obligatoires pour faire avancer l’histoire. Le scénario doit avoir une fin alternative (voir les autres features).
*        Une difficulté choisie : La difficulté doit pouvoir être choisie par le joueur au début de chaque rush pour lui permettre de jouer comme bon lui semble.
*    Plus la difficulté est élevée, plus les récompenses sont élevées. Les récompenses sont sous forme d’or utilisé pour améliorer de façon persistante
*    son héros (voir “De la persistance entre les rush”). De plus, seule la difficulté maximum permet de découvrir la fin alternative du jeu.
*        De la persistance entre les rush : Le joueur doit pouvoir perfectionner son personnage avec des améliorations persistantes
*    entre les rush. C’est à dire que le joueur recommence, certes depuis le début avec un nouveau héros à chaque nouveau rush, mais grâce à ces améliorations, le joueur progresse en
*    puissance de rush en rush. Cela lui permet de faire des rush plus facilement ou d’augmenter la difficulté jusqu'à pouvoir survivre en difficulté maximale et découvrir la fin alternative du jeu.
*    Cependant, pour permettre à tous les joueurs, y compris les moins bons, de pouvoir accéder à cette fin alternative, celle-ci.
*    est aussi visible à partir du moment où toutes les améliorations persistantes ont été débloquées (ce qui implique un certain temps de jeu).
*        Des combats en tour par tour et de la gestion de ressources : Lorsque le joueur rencontre un ennemi dans une salle, un combat s’engage. Le joueur
*    gagne de la pression à chaque tour, jusqu’à atteindre un niveau de pression maximum. Chaque action dépense de la pression. Le joueur peut programmer jusqu’à cinq actions à chaque tour.
*    Le héros est composé de cinq parties (tête, torse, jambes, bras droit, bras gauche). Une action est une combinaison d’une de ces parties et d’une direction (haut, bas, gauche, droite). Par
*    exemple, si le joueur programme Jambes Droite, il se déplace à droite, ou encore Jambes Haut, il saute. Le joueur et l’ennemi se déplacent le long d’une ligne de cases donc sur un seul
*    axe. Toute la pression utilisée pendant un combat sera déduite de la réserve de vapeur du héros  à la fin du combat, s’il est toujours vivant. Il faudra donc que le joueur utilise judicieusement ses
*    actions afin de ne pas manquer de vapeur. Sinon il sera obligé de convertir son or gagné jusqu’ici en vapeur. Et s’il vient à manquer d’or et de vapeur, le rush se termine tout simplement.
*        Des graphiques simples mais efficaces et une interface claire et détaillée : Les graphiques doivent être simples mais efficaces pour ne pas passer trop de temps à
*    les réaliser. Ils pourront faire l’objet d'améliorations si le temps et les ressources le permettent. L’interface doit être claire et détaillée pour permettre au joueur de bien comprendre les
*    mécanismes du jeu. Par exemple, au début d’un rush, après la génération aléatoire du héros, le joueur peut choisir certaines parties de son héros pour les redéterminer
*    de manière aléatoire. Il faut donc qu’il puisse comprendre et savoir précisément ce que lui apporte chaque partie et ainsi pouvoir agir en combat de manière réfléchie.
*
* \section Idée originale de Pierre CASATI et Damien CLARAS.
*/


#endif // DOC_HPP_INCLUDED
