using System;
using System.Collections.Generic;
using System.Data;
using System.Data.Entity;
using System.Linq;
using System.Net;
using System.Web;
using System.Web.Mvc;
using _MY_PAGE.Models;

namespace _MY_PAGE.Controllers
{
    public class Rodzaj_PaliwaController : Controller
    {
        private ApplicationDbContext db = new ApplicationDbContext();

        // GET: Rodzaj_Paliwa
        public ActionResult Index()
        {
            return View(db.Fuel_Type.ToList());
        }

        // GET: Rodzaj_Paliwa/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Rodzaj_Paliwa rodzaj_Paliwa = db.Fuel_Type.Find(id);
            if (rodzaj_Paliwa == null)
            {
                return HttpNotFound();
            }
            return View(rodzaj_Paliwa);
        }

        // GET: Rodzaj_Paliwa/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Rodzaj_Paliwa/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "ID,Nazwa_Rodzaj")] Rodzaj_Paliwa rodzaj_Paliwa)
        {
            if (ModelState.IsValid)
            {
                db.Fuel_Type.Add(rodzaj_Paliwa);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(rodzaj_Paliwa);
        }

        // GET: Rodzaj_Paliwa/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Rodzaj_Paliwa rodzaj_Paliwa = db.Fuel_Type.Find(id);
            if (rodzaj_Paliwa == null)
            {
                return HttpNotFound();
            }
            return View(rodzaj_Paliwa);
        }

        // POST: Rodzaj_Paliwa/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "ID,Nazwa_Rodzaj")] Rodzaj_Paliwa rodzaj_Paliwa)
        {
            if (ModelState.IsValid)
            {
                db.Entry(rodzaj_Paliwa).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(rodzaj_Paliwa);
        }

        // GET: Rodzaj_Paliwa/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Rodzaj_Paliwa rodzaj_Paliwa = db.Fuel_Type.Find(id);
            if (rodzaj_Paliwa == null)
            {
                return HttpNotFound();
            }
            return View(rodzaj_Paliwa);
        }

        // POST: Rodzaj_Paliwa/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Rodzaj_Paliwa rodzaj_Paliwa = db.Fuel_Type.Find(id);
            db.Fuel_Type.Remove(rodzaj_Paliwa);
            db.SaveChanges();
            return RedirectToAction("Index");
        }

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                db.Dispose();
            }
            base.Dispose(disposing);
        }
    }
}
