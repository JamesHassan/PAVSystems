function graphlab(Fg,Sub,x,y,Ax,XL,YL,TL)
%GRAPH Makes a sublot on a particular figure.
%   GRAPH(Fg,Sub,x,y,Ax,XL,YL,TL) makes a sublot
%   on a figure using the following parameters
%   Fg specifies the figure number.
%   Sub specifies the sublot coordinates.
%   x specifies the horizontal vector.
%   y specifies the vertical vector.
%   Ax specifies a vector containing the axes.
%   XL specifies the x-axis label.
%   YL specifies the y-axis label.
%   TL specifies the subplot title.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
figure (Fg);
subplot(Sub);
plot(x,y);
axis(Ax);
xlabel(XL);
ylabel(YL);
title(TL);

end

