#include "Rack.hpp"


namespace rack {

Scene::Scene() {
	scrollWidget = new ScrollWidget();
	{
		assert(!gRackWidget);
		gRackWidget = new RackWidget();
		scrollWidget->container->addChild(gRackWidget);
	}
	addChild(scrollWidget);

	toolbar = new Toolbar();
	addChild(toolbar);
	scrollWidget->box.pos.y = toolbar->box.size.y;
}

void Scene::setOverlay(Widget *w) {
	if (overlay) {
		removeChild(overlay);
		delete overlay;
		overlay = NULL;
	}
	if (w) {
		addChild(w);
		overlay = w;
		overlay->box.pos = Vec();
	}
}

void Scene::step() {
	toolbar->box.size.x = box.size.x;
	scrollWidget->box.size = box.size.minus(scrollWidget->box.pos);
	if (overlay) {
		overlay->box.size = box.size;
	}

	Widget::step();
}


} // namespace rack
