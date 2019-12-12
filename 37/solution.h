int tryToFill(vector<vector<char>>& board)//这个函数是在推理出了所有必填数而无法再推出更多必填数的时候，开始尝试假设填数而使用的。这个函数内并没有递归，所以假设只有一层。除了在做返回值时的判断，大部分代码和主函数是一样的。以下仅对和主程序不同的部分作注释
{
    const int dy[9]={0,0,0,1,1,1,2,2,2};
    const int dx[9]={0,1,2,0,1,2,0,1,2};

    int numsRemain=81;
    int previousNumsRemain=81;
    int possibleFillPos;
    bool rowFilled[9][9];
    bool columnFilled[9][9];
    bool ninePalaceFilled[9][9];

    for (int i=0;i<=8;i++)
    {
        for (int j=0;j<=8;j++)
        {
            rowFilled[i][j]=false;
            columnFilled[i][j]=false;
            ninePalaceFilled[i][j]=false;
        }
    }
    
    for (int y=0;y<=8;y++)
    {
        for (int x=0;x<=8;x++)
        {
            if (board[y][x]!='.')
            {
                int charPos=board[y][x]-49;
                int a=y/3;
                int b=x/3;

                rowFilled[y][charPos]=true;
                columnFilled[x][charPos]=true;
                ninePalaceFilled[a*3+b][charPos]=true;

                numsRemain--;
            }
        }
    }

    while (numsRemain>0)
    {
        if (previousNumsRemain>numsRemain)
            previousNumsRemain=numsRemain;
        else
            return 1;//剩余待填数目与上一次搜索时的数目相同，说明不能再推理出必填数了，这个假设无法证实也无法证伪，情况不明，返回1
        for (int charPos=0;charPos<=8;charPos++)
        {
            for (int y=0;y<=8;y++)
            {
                if (rowFilled[y][charPos])
                    continue;
                
                possibleFillPos=-1;

                for (int x=0;x<=8;x++)
                {
                    int a=y/3;
                    int b=x/3;

                    if ((board[y][x]=='.')&&(!columnFilled[x][charPos])&&(!ninePalaceFilled[a*3+b][charPos]))
                    {
                        if (possibleFillPos==-1)
                            possibleFillPos=x;
                        else
                        {
                            possibleFillPos=10;
                            break;
                        }
                    }
                }

                if (possibleFillPos==10)
                    continue;

                if (possibleFillPos==-1)
                    return 0;//枚举的数字在y行内无法填放，说明假设被证伪，返回0

                int a=y/3;
                int b=possibleFillPos/3;

                board[y][possibleFillPos]=charPos+49;

                rowFilled[y][charPos]=true;
                columnFilled[possibleFillPos][charPos]=true;
                ninePalaceFilled[a*3+b][charPos]=true;

                numsRemain--;
            }

            for (int x=0;x<=8;x++)
            {
                if (columnFilled[x][charPos])
                    continue;
                
                possibleFillPos=-1;

                for (int y=0;y<=8;y++)
                {
                    int a=y/3;
                    int b=x/3;

                    if ((board[y][x]=='.')&&(!rowFilled[y][charPos])&&(!ninePalaceFilled[a*3+b][charPos]))
                    {
                        if (possibleFillPos==-1)
                            possibleFillPos=y;
                        else
                        {
                            possibleFillPos=10;
                            break;
                        }
                    }
                }

                if (possibleFillPos==10)
                    continue;

                if (possibleFillPos==-1)
                    return 0;//枚举的数字在x列内无法填放，说明假设被证伪，返回0

                int a=possibleFillPos/3;
                int b=x/3;

                board[possibleFillPos][x]=charPos+49;

                rowFilled[possibleFillPos][charPos]=true;
                columnFilled[x][charPos]=true;
                ninePalaceFilled[a*3+b][charPos]=true;

                numsRemain--;
            }

            for (int i=0;i<=8;i++)
            {
                if (ninePalaceFilled[i][charPos])
                    continue;
                
                possibleFillPos=-1;

                for (int j=0;j<=8;j++)
                {
                    int y=dy[i]*3+dy[j];
                    int x=dx[i]*3+dx[j];

                    if ((board[y][x]=='.')&&(!rowFilled[y][charPos])&&(!columnFilled[x][charPos]))
                    {
                        if (possibleFillPos==-1)
                            possibleFillPos=j;
                        else
                        {
                            possibleFillPos=10;
                            break;
                        }
                    }
                }

                if (possibleFillPos==10)
                    continue;

                if (possibleFillPos==-1)
                    return 0;//枚举的数字在以(y,x)为左上角顶点的九宫格内无法填放，说明假设被证伪，返回0

                int y=dy[i]*3+dy[possibleFillPos];
                int x=dx[i]*3+dx[possibleFillPos];

                board[y][x]=charPos+49;

                rowFilled[y][charPos]=true;
                columnFilled[x][charPos]=true;
                ninePalaceFilled[i][charPos]=true;

                numsRemain--;
            }
        }
    }

    return 2;//所有数都已被推导，返回2
}

void solveSudoku(vector<vector<char>>& board)//主函数
{
    const int dy[9]={0,0,0,1,1,1,2,2,2};//y为行数，最上方为0，最下方为8
    const int dx[9]={0,1,2,0,1,2,0,1,2};//x为列数，最左边为0，最右边为8
    //dy、dx为相对位移，用以遍历九宫格

    int numsRemain=81;//待填数数量
    int previousNumsRemain=81;//上一次记录的待填数数量。如果在某次搜索过后，previousNumsRemain与numsRemain相同，则说明这次搜索没有推导出新的必填数，要开始尝试假设填数了
    int possibleFillPos;//枚举的数字可能的填充位置。初始值为-1，找到一个填充位置（0~8）则记录，如果找到有两个或以上的可填充位置，记为10。另：这个变量在不同段落的代码里表示的意义会不相同，比如在枚举某个数在某行里可能填充的位置时，这个变量就表示可以被填充进的列号，依此类推
    bool rowFilled[9][9];//rowFilled[i][j]表示在第i行中，j+1这个数是否已被填充，以下类似
    bool columnFilled[9][9];
    bool ninePalaceFilled[9][9];

    //初始化三个Filled数组的值为false

    for (int i=0;i<=8;i++)
    {
        for (int j=0;j<=8;j++)
        {
            rowFilled[i][j]=false;
            columnFilled[i][j]=false;
            ninePalaceFilled[i][j]=false;
        }
    }

    //根据已知数的信息更新变量
    
    for (int y=0;y<=8;y++)
    {
        for (int x=0;x<=8;x++)//枚举坐标点
        {
            if (board[y][x]!='.')//当某个格子内有已知数时
            {
                int charPos=board[y][x]-49;//charPos表示字符'1'~'9'（ASCII码为49~57）在数组中所应存放的位置（0~8）
                int a=y/3;
                int b=x/3;
                //对于某个点(y,x)，(y/3*3,x/3*3)是这个点所在九宫格的左上方格子的坐标
                //y/3*3+x/3代表是第几个九宫格
                //比如左上方格子坐标为(0,0)，是第0个九宫格
                //左上方格子坐标为(0,6)，是第2个九宫格
                //左上方格子坐标为(3,0)，是第3个九宫格
                //以此类推
                //所以这里算出a和b之后，下面a*3+b就代表是第几个九宫格

                rowFilled[y][charPos]=true;
                columnFilled[x][charPos]=true;
                ninePalaceFilled[a*3+b][charPos]=true;

                numsRemain--;
            }
        }
    }

    //开始进行推导，直到待填数的数量为0

    while (numsRemain>0)
    {
        if (previousNumsRemain>numsRemain)//numsRemain变少了，说明上次搜索有推导出新的必填数
            previousNumsRemain=numsRemain;
        else//否则，没有推导出新的必填数，就要开始尝试假设填数了
        {
            bool haveFilledNewValue=false;//这个变量记录，后面在尝试假设填数时，是否证伪了其中一个假设（而证实了另外一个假设）。如果出现了这种情况，则记为true，以跳出假设填数的过程，推导新的必填数

            for (int y=0;y<=8;y++)
            {
                for (int x=0;x<=8;x++)
                {
                    if (board[y][x]=='.')//这个位置的格子还未填
                    {
                        int possibleFillPosTotal=0;//记录这个格子还能填多少个数
                        int possibleFillPosTry[2];//数组大小为2，因为仅当这个格子能排除7个数，只剩下2个数能填时，才对这个格子做假设

                        int a=y/3;
                        int b=x/3;

                        for (int charPos=0;charPos<=8;charPos++)//枚举9个数
                        {
                            if ((!rowFilled[y][charPos])&&(!columnFilled[x][charPos])&&(!ninePalaceFilled[a*3+b][charPos]))//被枚举的数就目前看来没有冲突，可以尝试填进这个格子，再看是否能证明或证伪
                            {
                                possibleFillPosTotal++;
                                if (possibleFillPosTotal==3)
                                    break;
                                else
                                    possibleFillPosTry[possibleFillPosTotal-1]=charPos;
                            }
                        }

                        if (possibleFillPosTotal==3)//这个格子能填的数目>=3，就不去对这个格子进行假设了，continue以去对其它格子进行假设
                            continue;

                        vector<vector<char>> boardBackup=board;//备份board
                        board[y][x]=possibleFillPosTry[0]+49;//先尝试第一种假设

                        int tryToFillResult=tryToFill(board);//开始根据第一种假设进行推导填数。如果成功填完所有格子，返回2，如果被证伪返回0，如果不能确定，返回1

                        if (tryToFillResult==2)//根据第一种假设，成功推出了所有数
                            return;
                        if (tryToFillResult==0)//第一种假设被证伪了，那么第二种假设被证明
                        {
                            haveFilledNewValue=true;

                            board=boardBackup;
                            board[y][x]=possibleFillPosTry[1]+49;

                            rowFilled[y][possibleFillPosTry[1]]=true;
                            columnFilled[x][possibleFillPosTry[1]]=true;
                            ninePalaceFilled[a*3+b][possibleFillPosTry[1]]=true;

                            numsRemain--;
                        }
                        if (tryToFillResult==1)//第一种假设情况不明，准备尝试第二种假设
                        {
                            board=boardBackup;
                            board[y][x]=possibleFillPosTry[1]+49;

                            tryToFillResult=tryToFill(board);

                            if (tryToFillResult==2)//根据第二种假设，成功推出了所有数
                                return;
                            if (tryToFillResult==0)//第二种假设被证伪了，那么第一种假设被证明
                            {
                                haveFilledNewValue=true;

                                board=boardBackup;
                                board[y][x]=possibleFillPosTry[0]+49;

                                rowFilled[y][possibleFillPosTry[0]]=true;
                                columnFilled[x][possibleFillPosTry[0]]=true;
                                ninePalaceFilled[a*3+b][possibleFillPosTry[0]]=true;

                                numsRemain--;
                            }
                            if (tryToFillResult==1)//第二种假设的情况还是不明，那么放弃对这个格子进行假设，去看下一个格子
                                board=boardBackup;
                        }
                    }

                    if (haveFilledNewValue)//有假设被证实，跳出假设的过程以推导新的必填数
                        break;
                }

                if (haveFilledNewValue)//有假设被证实，跳出假设的过程以推导新的必填数
                    break;
            }
        }

        //以下为推导必填数的过程，分别推导某个数在某行/某列/某个九宫格内是否可以被填进唯一的位置。三段代码是类似的，故只对第一段代码作注释，后面两段可以类推

        for (int charPos=0;charPos<=8;charPos++)//分别枚举9个数
        {
            for (int y=0;y<=8;y++)//分别枚举9行
            {
                if (rowFilled[y][charPos])//看这个数在这行里是否已被填充。如果被填充，则去检查下一行
                    continue;

                //否则如果没被填充，那么看看这个数在这行里是否只能填进唯一列
                
                possibleFillPos=-1;//可以填进的列号，初始化值为-1

                for (int x=0;x<=8;x++)
                {
                    int a=y/3;
                    int b=x/3;

                    if ((board[y][x]=='.')&&(!columnFilled[x][charPos])&&(!ninePalaceFilled[a*3+b][charPos]))//没有冲突，说明这个数可以被填进x列中
                    {
                        if (possibleFillPos==-1)
                            possibleFillPos=x;
                        else//这个数有填进不止一列的可能性，记possibleFillPos为10
                        {
                            possibleFillPos=10;
                            break;
                        }
                    }
                }

                if (possibleFillPos==10)//这个数有填进不止一列的可能性，因此暂时推不出这个数在这行里必定填进的列号
                    continue;

                //否则，相当于推理出了这个数在这行里必定填的唯一列号，因此把它填进board中，并对几个Filled数组进行更新

                int a=y/3;
                int b=possibleFillPos/3;

                board[y][possibleFillPos]=charPos+49;

                rowFilled[y][charPos]=true;
                columnFilled[possibleFillPos][charPos]=true;
                ninePalaceFilled[a*3+b][charPos]=true;

                numsRemain--;
            }

            for (int x=0;x<=8;x++)
            {
                if (columnFilled[x][charPos])
                    continue;
                
                possibleFillPos=-1;

                for (int y=0;y<=8;y++)
                {
                    int a=y/3;
                    int b=x/3;

                    if ((board[y][x]=='.')&&(!rowFilled[y][charPos])&&(!ninePalaceFilled[a*3+b][charPos]))
                    {
                        if (possibleFillPos==-1)
                            possibleFillPos=y;
                        else
                        {
                            possibleFillPos=10;
                            break;
                        }
                    }
                }

                if (possibleFillPos==10)
                    continue;

                int a=possibleFillPos/3;
                int b=x/3;

                board[possibleFillPos][x]=charPos+49;

                rowFilled[possibleFillPos][charPos]=true;
                columnFilled[x][charPos]=true;
                ninePalaceFilled[a*3+b][charPos]=true;

                numsRemain--;
            }

            for (int i=0;i<=8;i++)
            {
                if (ninePalaceFilled[i][charPos])
                    continue;
                
                possibleFillPos=-1;

                for (int j=0;j<=8;j++)
                {
                    int y=dy[i]*3+dy[j];
                    int x=dx[i]*3+dx[j];

                    if ((board[y][x]=='.')&&(!rowFilled[y][charPos])&&(!columnFilled[x][charPos]))
                    {
                        if (possibleFillPos==-1)
                            possibleFillPos=j;
                        else
                        {
                            possibleFillPos=10;
                            break;
                        }
                    }
                }

                if (possibleFillPos==10)
                    continue;

                int y=dy[i]*3+dy[possibleFillPos];
                int x=dx[i]*3+dx[possibleFillPos];

                board[y][x]=charPos+49;

                rowFilled[y][charPos]=true;
                columnFilled[x][charPos]=true;
                ninePalaceFilled[i][charPos]=true;

                numsRemain--;
            }
        }
    }
}