## 🖥️ **Terminal + Git Cheatsheet (voor Beginners)**
> **Geschreven door:** Steven Slaa

### 📁 Terminal Basics

| Commando            | Uitleg                  |
| ------------------- | ----------------------- |
| `pwd`               | Toon je huidige map     |
| `ls`                | Toon inhoud van een map |
| `cd mapnaam`        | Ga naar een map toe     |
| `cd ..`             | Ga één map omhoog       |
| `mkdir mapnaam`     | Maak een nieuwe map     |
| `touch bestand.txt` | Maak een leeg bestand   |
| `cat bestand.txt`   | Toon inhoud bestand     |
| `rm bestand.txt`    | Verwijder een bestand   |
| `rmdir map`         | Verwijder een map       |
| `clear`             | Maak het scherm schoon  |

---

## 🗃️ **Git Basics**

### 🔧 Een nieuwe Git repository starten

| Commando        | Uitleg                                               |
| --------------- | ---------------------------------------------------- |
| `git init`      | Start een nieuwe Git-repository in de huidige map    |
| `git clone URL` | Download een bestaande repository (zoals van GitHub) |

### ✏️ Wijzigingen bijhouden

| Commando                       | Uitleg                                       |
| ------------------------------ | -------------------------------------------- |
| `git status`                   | Laat zien wat er veranderd is                |
| `git add bestand.txt`          | Voeg dit bestand toe aan de volgende commit  |
| `git add .`                    | Voeg **alle** veranderingen toe              |
| `git commit -m "Beschrijving"` | Sla de veranderingen op met een beschrijving |
| `git log`                      | Bekijk de geschiedenis van commits           |

### 🔁 Werken met een remote (zoals GitHub of Gitlab)

| Commando        | Uitleg                                        |
| --------------- | --------------------------------------------- |
| `git remote -v` | Toon gekoppelde servers (remotes)             |
| `git push`      | Stuur je commits naar de remote repository    |
| `git pull`      | Haal de nieuwste wijzigingen van de server op |
| `git clone URL` | Download een project van bijv. GitHub         |

---

### ✅ Handige combinaties

```bash
git status       # Kijk wat er is veranderd
git add .        # Voeg alles toe aan de commit
git commit -m "Je bericht"  # Sla de verandering op
git push         # Verstuur je commit naar GitHub
```

---

> 💡 **Tip:** Commit, met duidelijke beschrijvingen zoals `"fix score counter"` of `"add LED support"`.

> 🧪 **Let op:** Git is niet moeilijk, maar je moet het **regelmatig oefenen**. Gebruik Git bij elk project, zelfs als je een project alleen doet.
