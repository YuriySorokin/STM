https://git-scm.com/book/ru/v2/Основы-Git-Работа-с-удалёнными-репозиториями

gitk windows manager

git config --global user.name ___
git config --global user.email ___
git init
git add
**git status**
git branch
// просмотр текущих веток локально
https://selectel.ru/blog/tutorials/git-checkout-working-with-branches/
// создание новой ветки

git checkout -b branchNew
git checkout branch2 
// переключиться на вторую ветку
git push --set-upstream origin branch2
// push на репозиторий новой ветки branch2

git commit --amend
// изменить только сообщение вашего последнего коммита

git checkout master ( main )
git merge Branch2
// переход в основную ветку
// слияние указанной с основной
https://webdevkin.ru/courses/git/git-merge

git splash сохранение и переход в ветку
git branch -d <name>
удаление ветки

git stash save  "Bug fix"
временное сохранение локально
git stash save -a "Bug fix with files"