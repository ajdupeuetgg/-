%方法二：?_(?+1)=1/(?_?^2 )+1 
function [y]=mtdtwo(x0,tol,maxit)
    b=x0;
    for i=1:maxit
       x2=1+1/b^2;%平方倒数再加1 
       bk=b;
       b=x2;
       ab=abs(bk-b);
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
    end
    if i==maxit
        fprintf('迭代已达到最大次数，停止迭代\n')
        y=b;
        fprintf('迭代结果为：%.5f，迭代次数为：%d\n',y,i)
    end
end