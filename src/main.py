import matplotlib.pyplot as plt
from matplotlib.widgets import Slider
import pandas as pd
import numpy as np
import time

nodes = pd.read_csv("../bin/nodes.csv", sep = ',')
status = pd.read_csv("../bin/status.csv", sep = '|')

status.replace(['N', 'L', 'I', 'B'], [0, 1, 2, 3], inplace = True)

fig, ax = plt.subplots()
fig.set_figwidth(20)
fig.set_figheight(7)
fig.subplots_adjust(bottom = 0.1)

img = plt.imread("../bin/US Map.png")
ax.imshow(img)
ax.axis("off")

colors = np.array(["green", "orange", "red", "white"])

x_coef = (2135 - 206) / (122.2459 - 80.2086)
x_bias = 206 - (-122.2459) * x_coef
y_coef = (741 - 140) / (37.4639 - 47.3635)
y_bias = 140 - 47.3635 * y_coef

dic = {}
cities = np.empty((len(nodes), 3), dtype = np.dtype("U40"))

for idx, (city, state, lat, lng) in nodes.iterrows():
    dic[lng * x_coef + x_bias + lat * y_coef + y_bias] = idx
    cities[idx, :] = [str(city), str(state), 0]

note = ax.annotate("", (0, 0), xytext = (20,20), textcoords = "offset points",
                    bbox = dict(boxstyle = "round"),
                    arrowprops = dict(arrowstyle = "-"))
note.set_visible(False)

scatter = ax.scatter(nodes["Longitude"] * x_coef + x_bias, 
                        nodes["Latitude"] * y_coef + y_bias, 
                        c = 'g')

def update(idx):
    scatter = ax.scatter(nodes["Longitude"] * x_coef + x_bias, 
                        nodes["Latitude"] * y_coef + y_bias, 
                        c = colors[status.iloc[int(idx - 1)].to_numpy()])

    cities[:, 2] = status.iloc[int(idx - 1)]
    fig.canvas.draw_idle()

time_silder = Slider(
    ax = fig.add_axes([.17, .09, 0.69, 0.03]),
    label = 'Time (days)',
    valmin = 1,
    valmax = 300,
    valinit = 0,
    valfmt = '%d'
)

def update_note(idx):
    pos = scatter.get_offsets()[idx["ind"][0]]
    note.xy = pos
    (city, state, infect) = cities[dic[pos[0] + pos[1]]]
    note.set_text(city + ", " + state)
    note.get_bbox_patch().set_facecolor(colors[int(infect)])
    note.get_bbox_patch().set_alpha(0.7)

def hover(event):
    vis = note.get_visible()
    if event.inaxes == ax:
        f, idx = scatter.contains(event)
        if f:
            update_note(idx)
            note.set_visible(True)
            fig.canvas.draw_idle()
        elif vis:
                note.set_visible(False)
                fig.canvas.draw_idle()

fig.canvas.mpl_connect("motion_notify_event", hover)
time_silder.on_changed(update)
plt.show()