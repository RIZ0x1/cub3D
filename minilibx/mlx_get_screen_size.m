#import <AppKit/NSScreen.h>

void    mlx_get_screen_size(int *width, int *height)
{
    NSRect disp = [[NSScreen mainScreen] frame];
    *height = (int)disp.size.height;
    *width = (int)disp.size.width;
}

void	mlx_get_screen_width(int *width)
{
	NSRect disp = [[NSScreen mainScreen] frame];
	*width = (int)disp.size.width;
}

void	mlx_get_screen_height(int *height)
{
	NSRect disp = [[NSScreen mainScreen] frame];
	*height = (int)disp.size.width;
}