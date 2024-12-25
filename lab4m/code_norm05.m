u = [+1; -2; +3; -4]

A1 = 2 * rand(4, 4) - 1
current_norm1 = norm(A1, inf)
desired_norm1 = 0.5
A1 = A1 * (desired_norm1 / current_norm1)

A1m = (abs(A1) - A1) / 2
A1p = (abs(A1) + A1) / 2

f1 = u - A1 * u
eps = 0.0000000000001

um1 = u - 1
up1 = u + 1

i1 = 0
dists1 = []
u1_m = []
u2_m = []
u3_m = []
u4_m = []

u1_p = []
u2_p = []
u3_p = []
u4_p = []

while norm(up1 - um1, inf) > eps
    i1 = i1 + 1
    tmp = A1p * um1 - A1m * up1 + f1
    up1 = A1p * up1 - A1m * um1 + f1
    um1 = tmp
    um1'
    up1'
    dist = norm(up1 - um1, inf)
    if i1 <= 25
        u1_m = [u1_m, um1(1)]
        u2_m = [u2_m, um1(2)]
        u3_m = [u3_m, um1(3)]
        u4_m = [u4_m, um1(4)]

        u1_p = [u1_p, up1(1)]
        u2_p = [u2_p, up1(2)]
        u3_p = [u3_p, up1(3)]
        u4_p = [u4_p, up1(4)]
    end

    dists1 = [dists1, dist]
end

figure
iterations1 = 0:1:i1 - 1
semilogy(iterations1, dists1)
grid on
xlabel("iteration")
ylabel("||u_i^+ - u_i^-||_{\infty}")
title("Error on iteration")


hold on

% Создание подграфиков
figure; % Открыть новое окно для графиков
it = 1:1:25

% Первый подграфик
subplot(2, 2, 1); % Указание сетки 2x2 и положение 1
m1 = plot(it, u1_m); 
hold on
p1 = plot(it, u1_p)
l1 = yline(u(1))
hold on
grid on
legend([m1, l1, p1], {"u_i^-", "u_i", "u_i^+"})
title('u_i^{(1)}');
xlabel('Iteration');

% Второй подграфик
subplot(2, 2, 2); % Указание сетки 2x2 и положение 2
m2 = plot(it, u2_m);
hold on
p2 = plot(it, u2_p)
l2 = yline(u(2))
hold on
grid on
legend([m2, l2, p2], {"u_i^-", "u_i", "u_i^+"})
title('u_i^{(2)}');
xlabel('Iteration');

% Третий подграфик
subplot(2, 2, 3); % Указание сетки 2x2 и положение 3
m3 = plot(it, u3_m);
hold on
p3 = plot(it, u3_p)
l3 = yline(u(3))
hold on
grid on
legend([m3, l3, p3], {"u_i^-", "u_i", "u_i^+"})
title('u_i^{(3)}');
xlabel('Iteration');

% Четвёртый подграфик
subplot(2, 2, 4); % Указание сетки 2x2 и положение 4
m4 = plot(it, u4_m);
hold on
p4 = plot(it, u4_p)
l4 = yline(u(4))
hold on
grid on
legend([m4, l4, p4], {"u_i^-", "u_i", "u_i^+"})
title('u_i^{(4)}');
xlabel('Iteration');

sgtitle("Component-wise convergence over the first 25 iterations")


