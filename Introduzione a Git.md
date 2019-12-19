# Introduzione a Git

### Cos'è Git?

E' un sistema di versioning (controllo di versione), per gestire i cambiamenti dei file.
Tiene traccia di ciascun cambiamento che avviene nel tuo progetto, e chi li ha fatti.

Due sistemi:
> Distribuito
Centralizzato

# Comandi git

```bash
git init //Cartella git
git status //Controllare lo stato delle modifiche
git add "nomefile" //Aggiungere un file
git commit -m"messaggio" //"Tasto della fotocamera", Snapshot, registare un messaggio
git config --global user.email "email" //Configurazione git
git config --global user.name "username" //Configurazione git
git log //Storico dei commit realizzati
git log --oneline //In una sola line
git tag -a v1.0 -m "Messaggio" //Taggare i file
git revert "idcommit" //Torna indietro creando un altro commit uguale al precedente
git checkout[caratteri/tag] //Serve a cambiare il puntatore che di solitao punta all'ultimo commit, per controllare una versione precedente del programma
git checkout master //Torna all'ultimo commit
nano .bashrc //Per modificare aliases
aliases=gl = 'git log --oneline'
git reset --hard //Lascia inalterati i file non tracciati (file nuovi), torna al commit precedente di quelli tracciati
git clean -f //Elimina tutti gli untracked file

git branch -d "nomebranch" #Branch da eliminare
<<<<<<< HEAD
git checkout -b "nomebranch" #Crea branch e sposta il puntatore
git merge "nomebranch" #Esegue il merge del branch a cui si è fatto il checkout con il nome branch
git rebase "nomebranch" #tipologia di merge

git clone "link" # copia la cartella in locale
git checkout o/master #branch della repository remota
git fetch #funziona come il git pull

=======
git config --global core.editor nano
>>>>>>> 81746ff31449288d75128e808040465d7759c575
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
