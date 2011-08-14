#include <hxcpp.h>

#ifndef INCLUDED_nme_events_Event
#include <nme/events/Event.h>
#endif
#ifndef INCLUDED_nme_events_IEventDispatcher
#include <nme/events/IEventDispatcher.h>
#endif
namespace nme{
namespace events{

HX_DEFINE_DYNAMIC_FUNC5(IEventDispatcher_obj,addEventListener,)

HX_DEFINE_DYNAMIC_FUNC1(IEventDispatcher_obj,dispatchEvent,return )

HX_DEFINE_DYNAMIC_FUNC1(IEventDispatcher_obj,hasEventListener,return )

HX_DEFINE_DYNAMIC_FUNC3(IEventDispatcher_obj,removeEventListener,)

HX_DEFINE_DYNAMIC_FUNC1(IEventDispatcher_obj,willTrigger,return )


} // end namespace nme
} // end namespace events
