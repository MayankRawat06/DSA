Last login: Mon Aug  7 10:00:29 on console
➜  ~ cd Pro
cd: no such file or directory: Pro
➜  ~ cd Projects
➜  Projects cd Facial\ Recognition
➜  Facial Recognition git:(main) ✗ git remote add origin https://github.com/MayankRawat06/Face-Recognition.git
git branch -M main
git push -u origin main
error: src refspec main does not match any
error: failed to push some refs to 'https://github.com/MayankRawat06/Face-Recognition.git'
➜  Facial Recognition git:(main) ✗ git remote add origin https://github.com/MayankRawat06/Face-Recognition.git
error: remote origin already exists.
➜  Facial Recognition git:(main) ✗ git rm
fatal: No pathspec was given. Which files should I remove?
➜  Facial Recognition git:(main) ✗ git remote add origin https://github.com/MayankRawat06/Face-Recognition.git
error: remote origin already exists.
➜  Facial Recognition git:(main) ✗ rm -rf .git*

➜  Facial Recognition git status
fatal: not a git repository (or any of the parent directories): .git
➜  Facial Recognition git init
Initialized empty Git repository in /Users/mayankrawat/Projects/Facial Recognition/.git/
➜  Facial Recognition git:(main) ✗ git remote add origin https://github.com/MayankRawat06/Face-Recognition.git
➜  Facial Recognition git:(main) ✗ git branch -M main
git push -u origin main
error: src refspec main does not match any
error: failed to push some refs to 'https://github.com/MayankRawat06/Face-Recognition.git'
➜  Facial Recognition git:(main) ✗ git branch -M main
➜  Facial Recognition git:(main) ✗ git push -u origin main
error: src refspec main does not match any
error: failed to push some refs to 'https://github.com/MayankRawat06/Face-Recognition.git'
➜  Facial Recognition git:(main) ✗ git pull
There is no tracking information for the current branch.
Please specify which branch you want to merge with.
See git-pull(1) for details.

    git pull <remote> <branch>

If you wish to set tracking information for this branch you can do so with:

    git branch --set-upstream-to=origin/<branch> main

➜  Facial Recognition git:(main) ✗ git push
fatal: The current branch main has no upstream branch.
To push the current branch and set the remote as upstream, use

    git push --set-upstream origin main

To have this happen automatically for branches without a tracking
upstream, see 'push.autoSetupRemote' in 'git help config'.

➜  Facial Recognition git:(main) ✗ git push --set-upstream origin main
error: src refspec main does not match any
error: failed to push some refs to 'https://github.com/MayankRawat06/Face-Recognition.git'
➜  Facial Recognition git:(main) ✗ git pull --rebase origin main
fatal: couldn't find remote ref main
➜  Facial Recognition git:(main) ✗ git pull origin main
fatal: couldn't find remote ref main
➜  Facial Recognition git:(main) ✗ git remote add origin https://github.com/MayankRawat06/Face-Recognition.git
error: remote origin already exists.
➜  Facial Recognition git:(main) ✗ git push
fatal: The current branch main has no upstream branch.
To push the current branch and set the remote as upstream, use

    git push --set-upstream origin main

To have this happen automatically for branches without a tracking
upstream, see 'push.autoSetupRemote' in 'git help config'.

➜  Facial Recognition git:(main) ✗ git push -u origin main
error: src refspec main does not match any
error: failed to push some refs to 'https://github.com/MayankRawat06/Face-Recognition.git'
➜  Facial Recognition git:(main) ✗ git pull --rebase origin main

git push -u origin main
fatal: couldn't find remote ref main
error: src refspec main does not match any
error: failed to push some refs to 'https://github.com/MayankRawat06/Face-Recognition.git'
➜  Facial Recognition git:(main) ✗ git add .
➜  Facial Recognition git:(main) ✗ git commit -m 'initial commit'
[main (root-commit) 740d0fb] initial commit
 1 file changed, 1550 insertions(+)
 create mode 100644 facialRecognition.ipynb
➜  Facial Recognition git:(main) git push
fatal: The current branch main has no upstream branch.
To push the current branch and set the remote as upstream, use

    git push --set-upstream origin main

To have this happen automatically for branches without a tracking
upstream, see 'push.autoSetupRemote' in 'git help config'.

➜  Facial Recognition git:(main) git push -u origin main
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Delta compression using up to 8 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 4.28 MiB | 1.95 MiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0

^C
➜  Facial Recognition git:(main) git status
On branch main
nothing to commit, working tree clean
➜  Facial Recognition git:(main) cd ..
➜  Projects cd ..
➜  ~ cd DSA
➜  DSA git:(main) cd Arrays
➜  Arrays git:(main) pbpaste > search-in-a-2d-matrix.cpp
➜  Arrays git:(main) ✗ vim search-in-a-2d-matrix.cpp
➜  Arrays git:(main) ✗ git add .
➜  Arrays git:(main) ✗ git commit -m 'add gfg qs'
[main 73fb4e1] add gfg qs
 1 file changed, 18 insertions(+)
 create mode 100644 Arrays/search-in-a-2d-matrix.cpp
➜  Arrays git:(main) git push
Enumerating objects: 6, done.
Counting objects: 100% (6/6), done.
Delta compression using up to 8 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (4/4), 600 bytes | 600.00 KiB/s, done.
Total 4 (delta 2), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/MayankRawat06/DSA.git
   cd45509..73fb4e1  main -> main
➜  Arrays git:(main) git push
Everything up-to-date
➜  Arrays git:(main) pbpaste > 74.search-a-2d-matrix.cpp
➜  Arrays git:(main) ✗ vim 74.search-a-2d-matrix.cpp
➜  Arrays git:(main) ✗ git add .
➜  Arrays git:(main) ✗ git commit -m 'add LC 74'
[main 873a619] add LC 74
 1 file changed, 14 insertions(+)
 create mode 100644 Arrays/74.search-a-2d-matrix.cpp
➜  Arrays git:(main) git push
Enumerating objects: 6, done.
Counting objects: 100% (6/6), done.
Delta compression using up to 8 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (4/4), 585 bytes | 585.00 KiB/s, done.
Total 4 (delta 2), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/MayankRawat06/DSA.git
   73fb4e1..873a619  main -> main
➜  Arrays git:(main) pbpaste > 169.majority-element.cpp
➜  Arrays git:(main) ✗ vim 169.majority-element.cpp
➜  Arrays git:(main) ✗ git add .
➜  Arrays git:(main) ✗ git commit -m 'add LC 169;
quote> :q
quote>
➜  Arrays git:(main) ✗ git commit -m 'add LC 169'
:q
[main 09f4253] add LC 169
 1 file changed, 20 insertions(+)
 create mode 100644 Arrays/169.majority-element.cpp
zsh: command not found: :q
➜  Arrays git:(main) git push
Enumerating objects: 6, done.
Counting objects: 100% (6/6), done.
Delta compression using up to 8 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (4/4), 598 bytes | 598.00 KiB/s, done.
Total 4 (delta 2), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/MayankRawat06/DSA.git
   873a619..09f4253  main -> main
➜  Arrays git:(main) vim 169.majority-element.cpp
➜  Arrays git:(main) cd ..
➜  DSA git:(main) cd DP
➜  DP git:(main) pbpaste
class Solution {
    int n;
    vector<int> dp;
    int f(int i, string& c, vector<int>& t, int prevc, int prevt) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        if(c[i] == prevc) return dp[i] = min(prevt, t[i]) + f(i + 1, c, t, prevc, max(prevt, t[i]));
        else return dp[i] = f(i + 1, c, t, c[i], t[i]);
    }
public:
    int minCost(string c, vector<int>& t) {
        n = t.size();
        dp.resize(n, -1);
        return f(0, c, t, 'A', 0);
    }
};%
➜  DP git:(main) pbpaste > 1578.minimum-time-to-make-rope-colorful.cpp
➜  DP git:(main) ✗ git add .
➜  DP git:(main) ✗ git commit -m 'add LC 1578'
[main b00ae75] add LC 1578
 1 file changed, 16 insertions(+)
 create mode 100644 DP/1578.minimum-time-to-make-rope-colorful.cpp
➜  DP git:(main) git push
Enumerating objects: 6, done.
Counting objects: 100% (6/6), done.
Delta compression using up to 8 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (4/4), 599 bytes | 599.00 KiB/s, done.
Total 4 (delta 2), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (2/2), completed with 2 local objects.
To https://github.com/MayankRawat06/DSA.git
   09f4253..b00ae75  main -> main
➜  DP git:(main) pbpaste > 1578.minimum-time-to-make-rope-colorful.cpp