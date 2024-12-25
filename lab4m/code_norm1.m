u2 = [1, -2, 3, -4]'

A2 = [
    0.33  -0.05  -0.21   0.37;
   -0.35  -0.31   0.30   0.03;
    0.00  -0.35   0.52   0.10;
   -0.31   0.41  -0.05   0.21
];

A2m = (abs(A2) - A2) / 2
A2p = (abs(A2) + A2) / 2

f2 = u2 - A2 * u2

eps = 0.0000000001

u2m = u2 - 1
u2p = u2 + 1

i2 = 0
dists2 = []
u1_m2 = []
u2_m2 = []
u3_m2 = []
u4_m2 = []

u1_p2 = []
u2_p2 = []
u3_p2 = []
u4_p2 = []

while norm(u2p - u2m, inf) > eps
    i2 = i2 + 1
    tmp = A2p * u2m - A2m * u2p + f2
    u2p = A2p * u2p - A2m * u2m + f2
    u2m = tmp
    u2m'
    u2p'
    dist = norm(u2p - u2m, inf)
    dists2 = [dists2, dist]
    if i2 <= 25
        u1_m2 = [u1_m2, u2m(1)]
        u2_m2 = [u2_m2, u2m(2)]
        u3_m2 = [u3_m2, u2m(3)]
        u4_m2 = [u4_m2, u2m(4)]

        u1_p2 = [u1_p2, u2p(1)]
        u2_p2 = [u2_p2, u2p(2)]
        u3_p2 = [u3_p2, u2p(3)]
        u4_p2 = [u4_p2, u2p(4)]
    end
end

iterations2 = 1:1:i2
semilogy(iterations2, dists2)
legend("||A||_{\infty} = 0.5", "||A||_{\infty} = 0.99")

% Создание подграфиков
figure; % Открыть новое окно для графиков
it = 1:1:25

% Первый подграфик
subplot(2, 2, 1); % Указание сетки 2x2 и положение 1
m1 = plot(it, u1_m2); 
hold on
p1 = plot(it, u1_p2)
l1 = yline(u(1))
hold on
grid on
legend([m1, l1, p1], {"u_i^-", "u_i", "u_i^+"})
title('u_i^{(1)}');
xlabel('Iteration');

% Второй подграфик
subplot(2, 2, 2); % Указание сетки 2x2 и положение 2
m2 = plot(it, u2_m2);
hold on
p2 = plot(it, u2_p2)
l2 = yline(u(2))
hold on
grid on
legend([m2, l2, p2], {"u_i^-", "u_i", "u_i^+"})
title('u_i^{(2)}');
xlabel('Iteration');

% Третий подграфик
subplot(2, 2, 3); % Указание сетки 2x2 и положение 3
m3 = plot(it, u3_m2);
hold on
p3 = plot(it, u3_p2)
l3 = yline(u(3))
hold on
grid on
legend([m3, l3, p3], {"u_i^-", "u_i", "u_i^+"})
title('u_i^{(3)}');
xlabel('Iteration');

% Четвёртый подграфик
subplot(2, 2, 4); % Указание сетки 2x2 и положение 4
m4 = plot(it, u4_m2);
hold on
p4 = plot(it, u4_p2)
l4 = yline(u(4))
hold on
grid on
legend([m4, l4, p4], {"u_i^-", "u_i", "u_i^+"})
title('u_i^{(4)}');
xlabel('Iteration');

sgtitle("Component-wise convergence over the first 25 iterations")
hold off