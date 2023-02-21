// gcc -o define define.c && ./define

#define PI 3.141592
#define SECS_PER_MIN 60
#define MINS_PER_HOUR 60
#define HOURS_PER_DAY 24

int main(void)
{
    int secs, mins, hours, days;
    double circumf, radius;
    int timer = 75;

    circumf = 2 * PI * radius;
    if (timer >= SECS_PER_MIN)
    {
        mins = mins + 1;
        timer = timer - SECS_PER_MIN;
    }
}
