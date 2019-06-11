% Digital Resonator
% James Hassan - 11991559
clc;
clear all;
close all;
%% Import .wav files
[originalAlarm,Fs] = audioread('SmokeAlarmSample.wav');

[input,Fs] = audioread('SmokeAlarm_addednoise.wav');

%sound(input,Fs);

% Plot audio file Waveform
dt = 1/Fs;
% plot of original Alarm
originalAlarm = originalAlarm(:,1);
t = 0:dt:(length(originalAlarm)*dt)-dt;
Time_axis_alarm = [0 (length(originalAlarm)*dt)-dt -max(originalAlarm) max(originalAlarm)];
graphlab(1,321,t,originalAlarm, Time_axis_alarm,'Seconds','Amplitude','Original Alarm Audio');

% plot of system input
input = input(:,1);
ti = 0:dt:(length(input)*dt)-dt;
Time_axis_input = [0 (length(input)*dt)-dt -max(input) max(input)];

graphlab(1,323,ti,input, Time_axis_input,'Seconds','Amplitude','Input Audio');

%plot(t,input); xlabel('Seconds'); ylabel('Amplitude');

%% Analysis of Data
% FFT spectrum of the original alarm
Length_OA=length(originalAlarm);
dfA=Fs/Length_OA;
frequency_range=-Fs/2:dfA:Fs/2-dfA;

FFT_alarm=fftshift(fft(originalAlarm))/length(fft(originalAlarm));
Freq_axis_alarm = [-Fs/2 Fs/2 0 abs(max(FFT_alarm))];
graphlab(1,322,frequency_range,abs(FFT_alarm), Freq_axis_alarm ,'Frequency(Hz)','Amplitude', 'FFT of Original Alarm Audio');

% FFT of the system input
Length_input = length(input);
dfI=Fs/Length_input;
frequency_range=-Fs/2:dfI:Fs/2-dfI;

FFT_input=fftshift(fft(input))/length(fft(input));
Freq_axis_in = [-Fs/2 Fs/2 0 abs(max(FFT_input))];
graphlab(1,324,frequency_range,abs(FFT_input), Freq_axis_in ,'Frequency(Hz)','Amplitude', 'FFT of Input Audio');

%% Find the frequency of the peak responce
[maxi,indexMax] = max(abs(FFT_alarm));
%fMaxActual = frequency_axis(indexMax)
fMax = abs(frequency_range(indexMax))

%% Filter and Resonator
Omr = 2*pi*fMax/Fs
r = 0.99995;
if (Length_OA > Length_input)
    longestSig = Length_OA;
    tOut = t;
else
    longestSig = Length_input;
    tOut = ti;
end

output = zeros(longestSig,1);

for n = 1:longestSig
    p = n;
    if n < 3
        if n == 1
            p = longestSig - 1;
        
        elseif n == 2
                p = longestSig;
        end
        
    end
    output(n) = 2*r*cos(Omr)*output(p-1) - output(p-2)*r^2 + input(n);
end

FFT_output = fftshift(fft(output))/length(fft(output));

Time_axis_out = [0 (length(output)*dt)-dt -max(output) max(output)];
Freq_axis_out = [-Fs/2 Fs/2 0 abs(max(FFT_output))];

graphlab(1,325,tOut,output, Time_axis_out,'Seconds','Amplitude','Resonator Output');
graphlab(1,326,frequency_range,abs(FFT_output), Freq_axis_out ,'Frequency(Hz)','Amplitude', 'FFT of Output Resonator');



%% Extra bits
% plot(frequency_axis,sys);
% [inputC,FsC] = audioread('AlarmClockSample.wav');
% [inputS,FsS] = audioread('SmokeAlarmSample.wav');
% 
% 
% % Alarm Clock Waveform
% inputC = inputC(:,1);
% dtC = 1/FsC;
% tC = 0:dtC:(length(inputC)*dtC)-dtC;
% A = tC;  
% figure
% plot(tC,inputC); xlabel('Seconds'); ylabel('Amplitude');
%     %figure
%     %plot(psd(spectrum.periodogram,input,'Fs',fs,'NFFT',length(input)));
% sound(inputC,FsC);
% 
% % Smoke Alarm Waveform
% inputS = inputS(:,1);
% dtS = 1/FsS;
% tS = 0:dtS:(length(inputS)*dtS)-dtS;
% S = tS;
% figure
% plot(tS,inputS); xlabel('Seconds'); ylabel('Amplitude');
% 
% Length_inputS=length(inputS);
% df=FsS/Length_inputS;
% frequency_axis=-FsS/2:df:FsS/2-df;
% fft(inputS);
% figure
% FFT_audio_in=fftshift(fft(inputS))/length(fft(inputS));
% plot(frequency_axis,abs(FFT_audio_in));
% title('FFT of Input Audio');
% xlabel('Frequency(Hz)');
% ylabel('Amplitude');
% % 
% wo = fMax/(fs/2);  bw = 20/(fs/2);
% [b,a] = iirpeak(wo,bw)
% %Res = iirpeak(wo,bw)
% %fvtool(b,a);
% Res = b/a
% r0 = 1
% r1 = -2*cos(Omr)
% r2 = 0.9999^2
% 
% aR1 = [1 r1 r2];
% bR1 = 1/r0;