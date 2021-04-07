%�����壺?_(?+1)=?_??(?_?^3??_?^2?1)/(3?_?^2?2?_? )
function [y]=mtdfive(x0,tol,maxit)%����������x0Ϊ������ֵ��tolΪ�������ȣ�maxitΪ����������
    b=x0;%�нӵ�����ֵ
    for i=1:maxit%�ڵ���������ѭ��
        b321=b^3-b^2-1;%�����
        b322=3*b^2-2*b;%���ĸ
        bk=b;%b(k)=b
        b=b-(b321)/(b322);%���        
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