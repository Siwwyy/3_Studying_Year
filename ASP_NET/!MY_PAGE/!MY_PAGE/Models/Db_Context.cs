using System.Data.Entity;
using System.Security.Claims;
using System.Threading.Tasks;
using Microsoft.AspNet.Identity;
using Microsoft.AspNet.Identity.EntityFramework;

namespace _MY_PAGE.Models
{
    public class ApplicationDbContext : IdentityDbContext
    {
        public DbSet<Informacje_w_ogloszeniu> Info { get; set; }
        public DbSet<Kraj_Pochodzenia> Country { get; set; }
        public DbSet<Marka_Pojazdu> Mark { get; set; }
        public DbSet<Model_Pojazdu> Model { get; set; }
        public DbSet<Rodzaj_Paliwa> Fuel_Type { get; set; }
        public DbSet<Sprzedawca> Seller { get; set; }
        public ApplicationDbContext()
            : base("DefaultConnection")
        { 
          
        }

        public static ApplicationDbContext Create()
        {
            return new ApplicationDbContext();
        }

    }
}