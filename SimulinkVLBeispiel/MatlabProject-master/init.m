%Init Function to load variables
clc;
clear all
close all

%readins 
h = load('Hoehe.txt');
v = load('Geschwindigkeit.txt');
t = load('Zeit.txt');

motor_data = xlsread('Motorkennlinie.xlsx');
motor_speed = motor_data(2:12,1);
motor_torque = motor_data(1,2:end); 
motor_power = motor_data(2:12,2:end); 
motor_max_torque = motor_data(end,2:end);

%Vorgaben
m = 2000; %Masse in kg
rho = 1.2; %a in kg/m^3
g = 9.81; % Gewichtskraft in m/s^2
Jg = 0.14; %Trägheitsmoment gesamt kg*m^2 
Aproj = 2.5; %porjezierte Fläche in m^2
rrad = 0.3; %Radius Rad in m
cw = 0.4; %Strömungswiderstandkoeffizient
fr = 0.015; %Rollwiderstand
nge = 0.98; %Wirkungsgrad Getriebe
P_consumer = 1050; %Leistung Verbraucher in W

 
%distance calculation 
s = cumtrapz(v);

%acceleration calculation 
a = diff(v)./diff(t);
a = [a;0]; %Dimensionen angleichen  


%a = gradient(v);


s_real = 0;
angle = 0;


for i=drange(1:length(s)-1)
    d_s = s(i+1)-s(i);
    d_h = h(i+1)-h(i);
    s_real = [s_real sqrt(d_s.^2 + d_h.^2)];
    angle =[angle atan(d_h/d_s)*180/pi]; 
   
end

%----Dimensionsangleichung der Vektoren für Plots-------%
s_real(1) = [];
angle(1) = [];
s_real(end+1) = 0;
angle(end+1) = 0;

s_real_cum = cumsum(s_real); 
v_real = gradient(s_real_cum); 


out = sim('master.slx');







