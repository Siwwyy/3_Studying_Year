using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(_MY_PAGE.Startup))]
namespace _MY_PAGE
{
    public partial class Startup
    {
        public void Configuration(IAppBuilder app)
        {
            ConfigureAuth(app);
        }
    }
}
