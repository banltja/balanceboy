%% Init 

close all; clear;
speed = 100;
myev3 = legoev3;
mymotor1 = motor(myev3,'A');
pause(4)

start(mymotor1);

%% set variables
t= 0;
x= 0;
startSpot = 0;
interv = 1000 ; % considering 1000 samples
step = 1 ; % lowering step has a number of cycles and then acquire more data
resetRotation(mymotor1);
rotation1 = 0; 


tic; % Start the stopwatch for timestamp
mymotor1.Speed = speed;
%% Start reading values
while ( rotation1 < 250 )

    t = [t, toc]; 
    rotation1 = readRotation(mymotor1);
    x = [ x, rotation1];
   
end
mymotor1.Speed = 0;


%% plot 
figure(1);
plot(t,x,'-o');

% calculate delta_t
a = x()
t_max = max(t);
t_size = size(t);
t_size = t_size(2);
t_delta = t_max/t_size; 
ax = gca;
ax.FontSize = 13;
xlabel('t[s]') 
ylabel('alpha') 
grid on; 

title('Sprungantwort IT1-Streckenverhalten','Antrieb Wippe');






