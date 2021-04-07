window1
windw2_select%所有输入与选择窗体已建立好

x0=str2double(input{1,1});
tol=str2double(input{2,1});
maxit=str2double(input{3,1});
%disp(mtdchoice);%所有输入与选择选项参数已建立好。

% 按ctrl+r进行多行注释
% 按ctrl+t取消多行注释
switch mtdchoice
    case 1
        mtdone(x0,tol,maxit);
    case 2
        mtdtwo(x0,tol,maxit);
    case 3
        mtdthird(x0,tol,maxit);
    case 4
        mtdfour(x0,tol,maxit);
    case 5
        mtdfive(x0,tol,maxit);
end
