# Introduzione a Git

### Cos'è Git?

E' un sistema di versioning (controllo di versione), per gestire i cambiamenti dei file.
Tiene traccia di ciascun cambiamento che avviene nel tuo progetto, e chi li ha fatti.

## Configurazione per cartella remota
```bash
git config --global user.email "email" #Configurazione della email
git config --global user.name "username" #Configurazione dell'username

git init #inizializza una repository

git clone "url" #Clona la repository in locale

git pus
```
## Comandi
```bash
git init #Inizializzare una repository .git
git status #Controllare lo stato delle modifiche e gli untracked file
git log #Storico dei commit realizzati
git log --oneline #Formato compresso

git add "nomefile" #Aggiungere un file alla lista per il prossimo commit
git add * (o .) #Aggiungi tutti i file alla lista per il prossimo commit

git commit -m"messaggio" #"Tasto della fotocamera", Snapshot, registare un messaggio

git config --global user.email "email" #Configurazione git
git config --global user.name "username" #Configurazione git

git tag -a v1.0 -m "Messaggio" //Taggare i file
git revert "idcommit" //Torna indietro creando un altro commit uguale al precedente
git checkout[caratteri/tag] //Serve a cambiare il puntatore che di solitao punta all'ultimo commit, per controllare una versione precedente del programma
git checkout master //Torna all'ultimo commit
nano .bashrc //Per modificare aliases
aliases=gl = 'git log --oneline'
git reset --hard //Lascia inalterati i file non tracciati (file nuovi), torna al commit precedente di quelli tracciati
git clean -f //Elimina tutti gli untracked file

git branch -d "nomebranch" #Branch da eliminare
git checkout -b "nomebranch" #Crea branch e sposta il puntatore
git merge "nomebranch" #Esegue il merge del branch a cui si è fatto il checkout con il nome branch
git rebase "nomebranch" #tipologia di merge


git branch -f "branchname" "position" # Riassegna il branch ad un commit specifico

git reset HEAD # Torna al commit precedente
git revert HEAD # Crea un commit successivo sovrascrivendo le modifiche


git clone "link" # copia la cartella in locale
git checkout o/master #branch della repository remota
git fetch #scarica la repository remota, ma non aggiorna il master
git pull #Aggiorna il master -> fetch e merge insieme
git push #Carica le modifiche nella repository remota

git fakeTeamwork "nome","numero" #esegue dei commit automatici per simulare che qualcuno abbia fatto delle modifiche

```

## Branch

Sono delle "linee indipendenti di sviluppo"

Ogni repository crea un branch chiamato "master", i commit vengono eseguiti sul branch master.
Per creare un nuovo branch, da un commit qualsiasi, si creerà un altro ramo, senza alterare il ramo master.

Al termine del ramo secondario, se si vuole mantenere le modifiche, si può fare un merge con il ramo master.

>https://learngitbranching.js.org/

## Remotes

Permette di creare delle repository locali scaricandole da github o gitlab ecc.

origin -> Nome di default per le repository remote

## Aliases
```bash
gl = git log --oneline
ga = git add
gc = git commit -m
gs = git status
```

# Ripasso

- Cos'è e come è strutturato
- Funzionalità di base
- Segui il tutorial https://www.e-fermi.it/moodle27/mod/url/view.php?id=17016 Fino a rewriting history

- Segui tutorial https://learngitbranching.js.org/ 
- Parti 1,2,3
- No Rebase
- Si Remote


## Introduzione

- Git è un sistema di controllo versione, (VCS, Version Control System), creato per    gestire le modifiche ai file.
- Permette di tracciare ogni modifica al proprio progetto, diventando quindi essenziale per la realizzazione dei progetti più impegnativi.

- Viene creato nel 2005 per sostituire "BitKeeper", di cui linux aveva perso la licenza.

### Inizializzare una repository

- git init 
Crea una repository .git dove potranno essere utilizzati tutti i comandi di Git

### Stato della repository

- git status
Mostra lo stato della repository, dove sono presenti i tracked e gli untracked file.
Git non traccia automaticamente i file

### Fare uno snapshot

- git add * (* per tutto)
Aggiunge i file allo snapshot per il prossimo commit
Lo snapshot rappresenta lo stato del progetto fino a quel momento

### Cartella remota

nome del branch = origin/master
"nomeremoto"/"nomebranch"

<!--stackedit_data:
eyJoaXN0b3J5IjpbNzk3NzQ1NjU4XX0=
-->