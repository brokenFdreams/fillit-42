git add .
git rm -r --cached *.dSYM
git rm -r --cached .idea
git rm -r --cached .vscode
git rm -r --cached .DS_Store
git rm -r --cached cmake-build-debug
git rm --cached CMakeLists.txt
git rm --cached gitcleanpush.sh
git rm --cached *.o
git commit -m "$1"
git push
