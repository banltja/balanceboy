%Matlab_Projekt

%readins und Vorgaben
h = load('Hoehe.txt');
v = load('Geschwindigkeit.txt');
t = load('Zeit.txt');
m = 2000; %Masse in kg
rho = 1.2; %a in kg/m^3
g = 9.81; % Gewichtskraft in m/s^2
Jg = 0.14; %Trägheitsmoment gesamt kg*m^2 
Aproj = 2.5; %porjezierte Fläche in m^2
rrad = 0.3; %Radius Rad in m
cw = 0.4; %Strömungswiderstandkoeffizient
fr = 0.015; %Rollwiderstand
nge = 0.98; %Wirkungsgrad Getriebe
P = 1050; %Leistung Verbraucher in W

 

b= tiledlayout(2,1);

nexttile
plot(t,h,'r')
grid on
ax = gca;                        % gets the current axes
ax.XAxisLocation = 'origin';     % sets them to zero
ax.YAxisLocation = 'origin';     % sets them to zero
ax.Box = 'off';% switches off the surrounding box
title('Höhenprofil')


nexttile
plot(t,v,'g')
grid on
ax = gca;                        % gets the current axes
ax.XAxisLocation = 'origin';     % sets them to zero
ax.YAxisLocation = 'origin';     % sets them to zero
ax.Box = 'off';                  % switches off the surrounding box
title('Geschwindigkeitsprofil')

