TP2 : Commande ESP32 depuis une page web Ubuntu

Objectif du TP
Comprendre comment un ESP32 peut :
- recevoir un ordre depuis une page web
- activer une LED ou un buzzer selon l’ordre reçu
- utiliser AJAX Fetch pour envoyer des commandes
- fonctionner comme un serveur web autonome

Ce TP fait suite au TP1 : Envoi de données ESP32 → Serveur Ubuntu.



Étape 1 : Ajouter des boutons dans la page web

Dans le fichier `index.php` du serveur Ubuntu, on ajoute :

- un bouton **Allumer** → envoie `/son` à l’ESP32  
- un bouton **Éteindre** → envoie `/led` à l’ESP32

Exemple :

```html
<h1>Commande ESP32</h1>

<button onclick="fetch('http://IP_ESP32/son')">Allumer</button>
<button onclick="fetch('http://IP_ESP32/led')">Éteindre</button>
