close all; clear;

speed = 100;

myev3 = legoev3;
mymotor1 = motor(myev3,'A');
mymotor2 = motor(myev3,'D');

resetRotation(mymotor1)
resetRotation(mymotor2)

pause(4)

mymotor1.Speed = speed;
mymotor2.Speed = speed;

start(mymotor1);
start(mymotor2);

t= 0;
x= 0;
startSpot = 0;
interv = 1000 ; % considering 1000 samples
step = 1 ; % lowering step has a number of cycles and then acquire more data
while ( t <interv )
    
    rotation1 = readRotation(mymotor1);
    rotation2 = readRotation(mymotor2);
    x = [ x, rotation1];
    plot(x) ;
    
      if ((t/step)-500 < 0) && rotation1<360
          startSpot = 0;
      elseif ((t/step)-500 < 0) && rotation1>360
          startSpot = 0;
          mymotor1.Speed = 0;
          mymotor2.Speed = 0;
%           stop(mymotor1);
%           stop(mymotor2);
      else
          startSpot = (t/step)-500;
      end
      
      axis([ startSpot, (t/step+5), 0 , rotation1+10 ]);
      grid
      t = t + step;
      drawnow;
%       pause(0.01)
end

stop(mymotor1);
stop(mymotor2);

  
