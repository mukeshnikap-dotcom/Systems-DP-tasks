# 1. Delete the hidden .git folder inside day1_shell
rm -rf day1_shell/.git

# 2. Clear Git's internal index cache for day1_shell
git rm --cached -r day1_shell/


# 3. Add all your files now
git add .

# 4. Commit the files (This will succeed now)
git commit -m "Initial commit including day1_shell files"

# 5. Push your branch up to GitHub
git push -u day1_shell main