%��������?_(?+1)=1/(?_?^2 )+1 
function [y]=mtdtwo(x0,tol,maxit)
    b=x0;
    for i=1:maxit
       x2=1+1/b^2;%ƽ�������ټ�1 
       bk=b;
       b=x2;
       ab=abs(bk-b);
       if b==Inf
           fprintf('���������ɢ�������壬ֹͣ����\n')
           fprintf('��������Ϊ��%d\n',i)
           break
        end
       if ab<tol
           fprintf('�����ѴﵽҪ�󾫶ȣ�ֹͣ����\n')
           fprintf('�������Ϊ��%.5f����������Ϊ��%d\n',b,i)
           break
        end%�����ж�
    end
    if i==maxit
        fprintf('�����Ѵﵽ��������ֹͣ����\n')
        y=b;
        fprintf('�������Ϊ��%.5f����������Ϊ��%d\n',y,i)
    end
end