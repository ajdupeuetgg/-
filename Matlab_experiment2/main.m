window1
windw2_select%����������ѡ�����ѽ�����

x0=str2double(input{1,1});
tol=str2double(input{2,1});
maxit=str2double(input{3,1});
%disp(mtdchoice);%����������ѡ��ѡ������ѽ����á�

% ��ctrl+r���ж���ע��
% ��ctrl+tȡ������ע��
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
