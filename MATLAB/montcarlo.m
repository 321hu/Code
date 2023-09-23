ErrorArea = [];
% n = 10000000;
for n = 1000:10:10000
    x = rand(n, 1) * 2;
    y = rand(n, 1) * 3;
    CntNum = 0;
    for k = 1:n
        if ((x(k)^2)/4 + (y(k)^2)/9 <= 1)
            CntNum = CntNum + 1;
        end
    end
    UnitCircleArea = 6 * 4 * CntNum / n;
    ExactArea = 6 * pi;
    ErrorArea = [ErrorArea abs(ExactArea - UnitCircleArea)];
end
% NumExp = size(ErrorArea, 1);
figure; plot(1000:10:10000, ErrorArea)