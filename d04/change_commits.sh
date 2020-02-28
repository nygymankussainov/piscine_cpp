git filter-branch -f --commit-filter '
        if [ "$GIT_COMMITTER_NAME" = "Valkyrie Hazelnut" ];
        then
                GIT_COMMITTER_NAME="Nygyman Kussainov";
                GIT_AUTHOR_NAME="nygymankussainov";
                GIT_COMMITTER_EMAIL="nygmankusainov23@gmail.com";
                GIT_AUTHOR_EMAIL="nygmankusainov23@gmail.com";
                git commit-tree "$@";
        else
                git commit-tree "$@";
        fi' HEAD