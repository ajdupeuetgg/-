%��������?_(?+1)=��(?_?^3?1)
function [y]=mtthird(x0,tol,maxit)
    b=x0;%�нӵ�����ֵ
    for i=1:maxit%�ڵ���������ѭ��
        x31=b^3-1;%��x0���η��ټ�1
        sqrb=sqrt(x31);
        bk=b;%b(k)=b
        b=sqrb;%��������������ȥ��
        ab=abs(bk-b);%��������ε���ֵ�����
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
    end%����ѭ��
    if i==maxit
        fprintf('�����Ѵﵽ��������ֹͣ����\n')
        y=b;
        fprintf('�������Ϊ��%.5f����������Ϊ��%d\n',y,i)
    end
end