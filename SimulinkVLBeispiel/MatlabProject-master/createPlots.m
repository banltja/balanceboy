close all
out = sim('master.slx');

%---------Strecke, Höhenprofil, Beschleunigung-----%
f1 = figure; 
figure(f1);
 
title('Velocity and Acceleration')
grid on
ax = gca;                        % gets the current axes
ax.XAxisLocation = 'origin';     % sets them to zero
ax.YAxisLocation = 'origin';     % sets them to zero
ax.Box = 'off';% switches off the surrounding box
yyaxis left
plot(t,v)
ylabel('velocity [m/s]')
xlabel('Time [s]')
hold on
yyaxis right
plot(t,a)
ylabel('accelaration [m/s^{2}]')
%getext ylabel('$acceleration [\frac{m}{s^{2}}]$','Interpreter','latex', 'FontSize', 13)
hold off
print(gcf,'-dpng','Geschwindikeit_Beschleunigung.png')


%--------Plots der Widerstände ---------------%
f2 = figure; 
figure(f2); 
b= tiledlayout(2,1);
nexttile; 
title('Driving Resistances')
%-------Luft vs. Geschwindigkeit--------%
grid on
ax = gca;                        % gets the current axes
ax.XAxisLocation = 'origin';     % sets them to zero
ax.YAxisLocation = 'origin';     % sets them to zero
ax.Box = 'off';% switches off the surrounding box
xlabel('Time [s]')
yyaxis left
plot(out.F_air);
ylabel('air drag [N]')
hold on
yyaxis right
plot(t,v_real)
ylabel('velocity [m/s]')


%----------Steigung vs Höhe-----------%
nexttile; 
grid on
ax = gca;                        % gets the current axes
ax.XAxisLocation = 'origin';     % sets them to zero
ax.YAxisLocation = 'origin';     % sets them to zero
ax.Box = 'off';% switches off the surrounding box
xlabel('Time [s]')
yyaxis left
plot(out.F_steig);
ylabel('downhill force [N]')
hold on
yyaxis right
plot(t,h)
ylabel('Height [m]')
axis([0 770 135 170])
print(gcf,'-dpng','Kräfte_2.png')


%---------Rollwiderstand vs. Höhe---------%
f3 = figure; 
figure(f3); 
bz= tiledlayout(2,1);

nexttile; 
title('Driving Resistances')
grid on
ax = gca;                        % gets the current axes
ax.XAxisLocation = 'origin';     % sets them to zero
ax.YAxisLocation = 'origin';     % sets them to zero
ax.Box = 'off';% switches off the surrounding box
xlabel('Time [s]')
yyaxis left
plot(out.F_roll);
axis([0 770 288 295])
ylabel('rolling resistance [N]')
hold on
yyaxis right
plot(t,h)
ylabel('Height [m]')
axis([0 770 135 170])

%---------Trägheit vs Beschleunigung---------%
nexttile; 
grid on
ax = gca;                        % gets the current axes
ax.XAxisLocation = 'origin';     % sets them to zero
ax.YAxisLocation = 'origin';     % sets them to zero
ax.Box = 'off';% switches off the surrounding box
xlabel('Time in [s]')
yyaxis left
ylabel('transducer force [N]')
hold on
plot(out.F_trans)
yyaxis right
plot(t,a)
ylabel('accelaration [m/s^{2}]')
axis([0 770 -6 8])
print(gcf,'-dpng','Kräfte_1.png')


%------Arbeitspunkt E-Maschine-------%
f4 = figure; 
figure(f4);

l = linspace(50,95, 30);
contourf(motor_torque,motor_speed,motor_power,[l], 'LineStyle','none', 'HandleVisibility', 'off')
hold on
plot(motor_torque,motor_max_torque,'c', 'Linewidth', 3.0, 'DisplayName', 'maximum torque limit');
scatter(out.n_motor,out.M_motor,[10],'r', 'DisplayName', 'operating points');
ylabel('torque M [Nm]')
xlabel('speed \omega [1/s]')
col = colorbar;
col.Title.String = '\eta [%]';
col.Title.FontSize = 15;
legend show
title('motor effiency and optimal operating conditions')
hold off
print(gcf,'-dpng','Arbeitspunkte_EMaschine.png')


%-------effektive Leistung-------%
f5 = figure; 
figure(5)
title('effective Power')

grid on
ax = gca;     %  gets the current axes
ax.XAxisLocation = 'origin';     % sets them to zero
%ax.YAxisLocation = 'origin';     % sets them to zero
ax.Box = 'off';% switches off the surrounding box
xlabel('Time in seconds')
yyaxis left
plot(t,out.P_batt)
ylabel('effective Power [W]')
yline(1050,'g','P_{consumer}')
hold on
plot(out.F_trans)
yyaxis right
plot(t,h)

ylabel('height [m]')
axis([0 770 135 170])
ax.YAxis(1).Exponent = 0;
print(gcf,'-dpng','effektive_Leistung.png')


