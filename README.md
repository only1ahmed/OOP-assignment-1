# OOP-assignment-1
in this repo the three of us (ahmed wesam - maya ayman - rawan younis) work on OOP assignment 1

----------------------------------------------------------------------------------------------------------------------------------------------
some git commands:


cd ~/Desktop
mkdir git-branches
cd git-branches
git init # start a repo
git add .
git commit -m "First commit" # make the first commit
git branch testBranch # create branch
git checkout testBranch # move to branch
## can also do git checkout -b testBranch
echo "Some text" > file.txt 
git add file.txt
git commit -m "Added a file with text"
git checkout master
echo "Text in another file" > new-file.txt
git add new-file.txt
git commit -m "Added another file"
git log --graph --oneline --decorate --all
# This command is long, so shorten it using aliases
git config --global alias.lg 'log --graph --oneline --decorate --all'
git merge testBranch
git lg
git branch -d testBranch # delete the branch
---------------------------------------------------------------------------------------------
cd - change directory
directory - the same thing as a folder
mkdir - make a directory
echo - print a message to the screen or to a file if > (redirect) is present.
git init - start or initialize a git repository
git add - put a file into the staging area, so that git starts tracking it
git commit - send files in the staging/index area into the history (the git repository)
git log --graph --oneline --decorate --all - view the commit history in the git repository and the branches, with each commit as one line.
git branch - An individual line of commit history that contains files that may differ from other branches.
git checkout - A way to move across the git commits and branches.
git merge - Combine a branch into the current checked out branch (i.e. the branch you are on).