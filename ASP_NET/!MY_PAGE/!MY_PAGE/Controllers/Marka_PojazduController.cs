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
    public class Marka_PojazduController : Controller
    {
        private ApplicationDbContext db = new ApplicationDbContext();

        // GET: Marka_Pojazdu
        public ActionResult Index()
        {
            return View(db.Mark.ToList());
        }

        // GET: Marka_Pojazdu/Details/5
        public ActionResult Details(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Marka_Pojazdu marka_Pojazdu = db.Mark.Find(id);
            if (marka_Pojazdu == null)
            {
                return HttpNotFound();
            }
            return View(marka_Pojazdu);
        }

        // GET: Marka_Pojazdu/Create
        public ActionResult Create()
        {
            return View();
        }

        // POST: Marka_Pojazdu/Create
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create([Bind(Include = "ID,Nazwa_Marka")] Marka_Pojazdu marka_Pojazdu)
        {
            if (ModelState.IsValid)
            {
                db.Mark.Add(marka_Pojazdu);
                db.SaveChanges();
                return RedirectToAction("Index");
            }

            return View(marka_Pojazdu);
        }

        // GET: Marka_Pojazdu/Edit/5
        public ActionResult Edit(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Marka_Pojazdu marka_Pojazdu = db.Mark.Find(id);
            if (marka_Pojazdu == null)
            {
                return HttpNotFound();
            }
            return View(marka_Pojazdu);
        }

        // POST: Marka_Pojazdu/Edit/5
        // To protect from overposting attacks, please enable the specific properties you want to bind to, for 
        // more details see https://go.microsoft.com/fwlink/?LinkId=317598.
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit([Bind(Include = "ID,Nazwa_Marka")] Marka_Pojazdu marka_Pojazdu)
        {
            if (ModelState.IsValid)
            {
                db.Entry(marka_Pojazdu).State = EntityState.Modified;
                db.SaveChanges();
                return RedirectToAction("Index");
            }
            return View(marka_Pojazdu);
        }

        // GET: Marka_Pojazdu/Delete/5
        public ActionResult Delete(int? id)
        {
            if (id == null)
            {
                return new HttpStatusCodeResult(HttpStatusCode.BadRequest);
            }
            Marka_Pojazdu marka_Pojazdu = db.Mark.Find(id);
            if (marka_Pojazdu == null)
            {
                return HttpNotFound();
            }
            return View(marka_Pojazdu);
        }

        // POST: Marka_Pojazdu/Delete/5
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken]
        public ActionResult DeleteConfirmed(int id)
        {
            Marka_Pojazdu marka_Pojazdu = db.Mark.Find(id);
            db.Mark.Remove(marka_Pojazdu);
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
