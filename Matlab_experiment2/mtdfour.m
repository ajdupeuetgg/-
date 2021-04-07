%�����ģ�?_(?+1)=?(?_?^2+1)
function [y]=mtdfour(x0,tol,maxit)%����������x0Ϊ������ֵ��tolΪ�������ȣ�maxitΪ����������
    b=x0;%�нӵ�����ֵ
    for i=1:maxit%�ڵ���������ѭ��
        b21=b^2+1;%��bƽ���ټ�1
        bk=b;%b(k)=b
        b=b21^(1/3);%��b21�����η���
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