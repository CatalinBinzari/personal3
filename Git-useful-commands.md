# Git useful commands

- `git clone https://gitlab.com/project.git` - creates a local copy of the repository
- `git status` - prints out the status of the local repo
- `git branch` - prints out local branches
- `git branch -a` - prints out all branches (local + remote)
- `git branch <branch_name>` - creates a new branch (without switching to it)
- `git checkout <branch_name>` - switches the current branch to the given branch
- `git checkout -b <branch_name>` - creates a new branch and switches the current branch to it
- `git checkout –b <new_b> <source_b>` - creates a new branch based on another one
- `git checkout <file_name>` - brings a file to the state it has on the repo (overwrites local changes)
- `git fetch` - updates the status of the local repo (but does not change the files)
- `git pull` - brings local branch up to date (does `git fetch` and updates the files)
- `git add file1 file2 dir1` - stages the given files (prepares them for commit)
- `git commit -m "message"` - commits the staged files into the local repo
- `git push -u origin branch1` - pushes the local commits into the remote repo
- `git merge source_branch` - merges the source branch into the current one; NOTE: Use the merging functionality from the Git Web UI
