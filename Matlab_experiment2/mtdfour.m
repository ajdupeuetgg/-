%方法四：?_(?+1)=?(?_?^2+1)
function [y]=mtdfour(x0,tol,maxit)%三个参数：x0为迭代初值，tol为迭代精度，maxit为最大迭代次数
    b=x0;%承接迭代初值
    for i=1:maxit%在迭代次数内循环
        b21=b^2+1;%求b平方再加1
        bk=b;%b(k)=b
        b=b21^(1/3);%给b21开三次方根
        ab=abs(bk-b);%求最近两次迭代值的相差
        if b==Inf
           fprintf('迭代结果发散，无意义，停止迭代\n')
           fprintf('迭代数次为：%d\n',i)
           break
        end
        if ab<tol
           fprintf('迭代已达到要求精度，停止迭代\n')
           fprintf('迭代结果为：%.5f，迭代次数为：%d\n',b,i)
           break
        end%精度判断
    end%迭代循环
    if i==maxit
        fprintf('迭代已达到最大次数，停止迭代\n')
        y=b;
        fprintf('迭代结果为：%.5f，迭代次数为：%d\n',y,i)
    end
end