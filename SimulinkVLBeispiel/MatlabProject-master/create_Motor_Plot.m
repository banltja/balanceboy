close all
out = sim('master.slx');

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
