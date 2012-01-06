/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                  G A T E                                  *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Gate_include__
#define __Gate_include__

#include "object/chain.h"

class Gate : public Chain  {
private:
    
    bool queue;

public:

  Gate(){
      queue = false;
  }

  virtual ~Gate(){
  }

   virtual bool prologue() = 0;

   virtual void epilogue() = 0;

   void queued(bool q){
       queue = q;
   }

   bool queued() const{
	   return queue;
   }
};

#endif
