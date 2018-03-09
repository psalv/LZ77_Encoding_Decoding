clear ; close all; clc

data = load('goldhill.raw.pgm.256.lengths.csv')';

max_val = max(data(1, :));

log_data = log(data(2, :));
for i = 1:size(log_data')
	if(log_data(i)) == 0
		log_data(i) = 0.1;
	endif
endfor

bar([0:max_val], log_data, 'BarWidth', 1)
axis([-2 max_val+2 0 max(log_data)+1])
ylabel('log(Frequency)'); 
xlabel('Length of match');
title('Frequency of different match lengths - Goldhill - Buffer: 256');
set(gca, 'xtick', [0:ceil((max_val+1)/20):max_val]);

print -dpsc figures/256_lengths_goldhill.eps



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



clear ; close all; clc

data = load('goldhill.raw.pgm.1024.lengths.csv')';

max_val = max(data(1, :));

log_data = log(data(2, :));
for i = 1:size(log_data')
	if(log_data(i)) == 0
		log_data(i) = 0.1;
	endif
endfor

bar([0:max_val], log_data, 'BarWidth', 1)
axis([-2 max_val+2 0 max(log_data)+1])
ylabel('log(Frequency)'); 
xlabel('Length of match');
title('Frequency of different match lengths - Goldhill - Buffer: 1024');
set(gca, 'xtick', [0:ceil((max_val+1)/20):max_val]);

print -dpsc figures/1024_lengths_goldhill.eps



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



clear ; close all; clc

data = load('goldhill.raw.pgm.5120.lengths.csv')';

max_val = max(data(1, :));

log_data = log(data(2, :));
for i = 1:size(log_data')
	if(log_data(i)) == 0
		log_data(i) = 0.1;
	endif
endfor

bar([0:max_val], log_data, 'BarWidth', 1)
axis([-2 max_val+2 0 max(log_data)+1])
ylabel('log(Frequency)'); 
xlabel('Length of match');
title('Frequency of different match lengths - Goldhill - Buffer: 5120');
set(gca, 'xtick', [0:ceil((max_val+1)/20):max_val]);

print -dpsc figures/5120_lengths_goldhill.eps



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%




clear ; close all; clc

data = load('peppers.raw.pgm.256.lengths.csv')';

max_val = max(data(1, :));

log_data = log(data(2, :));
for i = 1:size(log_data')
	if(log_data(i)) == 0
		log_data(i) = 0.1;
	endif
endfor

bar([0:max_val], log_data, 'BarWidth', 1)
axis([-2 max_val+2 0 max(log_data)+1])
ylabel('log(Frequency)'); 
xlabel('Length of match');
title('Frequency of different match lengths - Peppers - Buffer: 256');
set(gca, 'xtick', [0:ceil((max_val+1)/20):max_val]);

print -dpsc figures/256_lengths_peppers.eps



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



clear ; close all; clc

data = load('peppers.raw.pgm.1024.lengths.csv')';

max_val = max(data(1, :));

log_data = log(data(2, :));
for i = 1:size(log_data')
	if(log_data(i)) == 0
		log_data(i) = 0.1;
	endif
endfor

bar([0:max_val], log_data, 'BarWidth', 1)
axis([-2 max_val+2 0 max(log_data)+1])
ylabel('log(Frequency)'); 
xlabel('Length of match');
title('Frequency of different match lengths - Peppers - Buffer: 1024');
set(gca, 'xtick', [0:ceil((max_val+1)/20):max_val]);

print -dpsc figures/1024_lengths_peppers.eps



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



clear ; close all; clc

data = load('peppers.raw.pgm.5120.lengths.csv')';

max_val = max(data(1, :));

log_data = log(data(2, :));
for i = 1:size(log_data')
	if(log_data(i)) == 0
		log_data(i) = 0.1;
	endif
endfor

bar([0:max_val], log_data, 'BarWidth', 1)
axis([-2 max_val+2 0 max(log_data)+1])
ylabel('log(Frequency)'); 
xlabel('Length of match');
title('Frequency of different match lengths - Peppers - Buffer: 5120');
set(gca, 'xtick', [0:ceil((max_val+1)/20):max_val]);

print -dpsc figures/5120_lengths_peppers.eps



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%% OFFSETS %%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



clear ; close all; clc

data = load('goldhill.raw.pgm.256.offsets.csv')';

max_val = max(data(1, :));

log_data = log(data(2, :));
for i = 1:size(log_data')
	if(log_data(i)) == 0
		log_data(i) = 0.1;
	endif
endfor

bar([0:max_val], log_data, 'BarWidth', 1)
axis([-2 max_val+2 0 max(log_data)+1])
ylabel('log(Frequency)'); 
xlabel('Distance to offset');
title('Frequency of offset positions - Goldhill - Buffer: 256');
set(gca, 'xtick', [0:ceil((max_val+1)/20):max_val]);

print -dpsc figures/256_offsets_goldhill.eps



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



clear ; close all; clc

data = load('goldhill.raw.pgm.1024.offsets.csv')';

max_val = max(data(1, :));

log_data = log(data(2, :));
for i = 1:size(log_data')
	if(log_data(i)) == 0
		log_data(i) = 0.1;
	endif
endfor

bar([0:max_val], log_data, 'BarWidth', 1)
axis([-2 max_val+2 0 max(log_data)+1])
ylabel('log(Frequency)'); 
xlabel('Distance to offset');
title('Frequency of offset positions - Goldhill - Buffer: 1024');
set(gca, 'xtick', [0:ceil((max_val+1)/20):max_val]);

print -dpsc figures/1024_offsets_goldhill.eps



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



clear ; close all; clc

data = load('goldhill.raw.pgm.5120.offsets.csv')';

max_val = max(data(1, :));

log_data = log(data(2, :));
for i = 1:size(log_data')
	if(log_data(i)) == 0
		log_data(i) = 0.1;
	endif
endfor

bar([0:max_val], log_data, 'BarWidth', 1)
axis([-2 max_val+2 0 max(log_data)+1])
ylabel('log(Frequency)'); 
xlabel('Distance to offset');
title('Frequency of offset positions - Goldhill - Buffer: 5120');
set(gca, 'xtick', [0:ceil((max_val+1)/10):max_val]);

print -dpsc figures/5120_offsets_goldhill.eps



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%




clear ; close all; clc

data = load('peppers.raw.pgm.256.offsets.csv')';

max_val = max(data(1, :));

log_data = log(data(2, :));
for i = 1:size(log_data')
	if(log_data(i)) == 0
		log_data(i) = 0.1;
	endif
endfor

bar([0:max_val], log_data, 'BarWidth', 1)
axis([-2 max_val+2 0 max(log_data)+1])
ylabel('log(Frequency)'); 
xlabel('Distance to offset');
title('Frequency of offset positions - Peppers - Buffer: 256');
set(gca, 'xtick', [0:ceil((max_val+1)/20):max_val]);

print -dpsc figures/256_offsets_peppers.eps



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



clear ; close all; clc

data = load('peppers.raw.pgm.1024.offsets.csv')';

max_val = max(data(1, :));

log_data = log(data(2, :));
for i = 1:size(log_data')
	if(log_data(i)) == 0
		log_data(i) = 0.1;
	endif
endfor

bar([0:max_val], log_data, 'BarWidth', 1)
axis([-2 max_val+2 0 max(log_data)+1])
ylabel('log(Frequency)'); 
xlabel('Distance to offset');
title('Frequency of offset positions - Peppers - Buffer: 1024');
set(gca, 'xtick', [0:ceil((max_val+1)/20):max_val]);

print -dpsc figures/1024_offsets_peppers.eps



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



clear ; close all; clc

data = load('peppers.raw.pgm.5120.offsets.csv')';

max_val = max(data(1, :));

log_data = log(data(2, :));
for i = 1:size(log_data')
	if(log_data(i)) == 0
		log_data(i) = 0.1;
	endif
endfor

bar([0:max_val], log_data, 'BarWidth', 1)
axis([-2 max_val+2 0 max(log_data)+1])
ylabel('log(Frequency)'); 
xlabel('Distance to offset');
title('Frequency of offset positions - Peppers - Buffer: 5120');
set(gca, 'xtick', [0:ceil((max_val+1)/10):max_val]);

print -dpsc figures/5120_offsets_peppers.eps

