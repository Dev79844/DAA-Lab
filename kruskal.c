#include<stdio.h>
#include<stdlib.h>

struct Edge {
    int src, dst, weight;
};
void swap_arr_element(struct Edge *dstEdge, struct Edge *srcEdge) {
    int temp;
    temp = dstEdge->src;
    dstEdge->src = srcEdge->src;
    srcEdge->src = temp;
    temp = dstEdge->dst;
    dstEdge->dst = srcEdge->dst;
    srcEdge->dst = temp;
    temp = dstEdge->weight;
    dstEdge->weight = srcEdge->weight;
    srcEdge->weight = temp;
}
int check_edge_validity(int vrtx, int parents[]) {
    if(parents[vrtx] == vrtx) {
        return vrtx;
    }
    return check_edge_validity(parents[vrtx], parents);
}
void sorting_edges(struct Edge *Edges[], int num_of_edges) {
    int i, j;
    struct Edge *tempEdge = (struct Edge *)malloc(sizeof(struct Edge));
    for (i = 1; i < num_of_edges; i++) {
        swap_arr_element(tempEdge, Edges[i]);
        j = i - 1;
        while (j >= 0 && Edges[j]->weight > tempEdge->weight) {
            swap_arr_element(Edges[j + 1], Edges[j]);
            j--;
        }
        swap_arr_element(Edges[j + 1], tempEdge);
    }
}
void finding_mst(struct Edge *Edges[], int num_of_vrtx, int num_of_edges) {
    int i, j, parents[num_of_vrtx], parent_src, parent_dst, mst_cost = 0;
    struct Edge *tempEdge = (struct Edge *)malloc(sizeof(struct Edge));
    sorting_edges(Edges, num_of_edges);
    printf("\nMST using Kruskal's algorithm:\n");
    for(i = 0; i < num_of_vrtx; i++) {
        parents[i] = i;
    }
    j = 0;
    for(i = 0; i < num_of_vrtx; i++) {
        tempEdge->src = Edges[i]->src;
        tempEdge->dst = Edges[i]->dst;
        tempEdge->weight = Edges[i]->weight;
        parent_src = check_edge_validity(tempEdge->src, parents);
        parent_dst = check_edge_validity(tempEdge->dst, parents);
        if(parent_src != parent_dst) {
            printf("\n(%c, %c) -> %d", tempEdge->src + 65, tempEdge->dst + 65, tempEdge->weight);
            parents[parent_src] = parent_dst;
            mst_cost += tempEdge->weight;
        }
    }
    printf("\nMST Cost: %d\n", mst_cost);

}
void main() {
    int num_of_vrtx, i, j, edge_counter = 0, w;
    printf("Enter number of vertices: ");
    scanf("%d", &num_of_vrtx);
    int max_edges = (num_of_vrtx * (num_of_vrtx - 1)) / 2;
    printf("Max possible edges: %d\n", max_edges);
    struct Edge *Edges[max_edges];
    printf("Enter weightage between vertices:\n");
    for(i = 0; i < num_of_vrtx; i++) {
        for(j = i; j < num_of_vrtx; j++) {
            if(i == j) continue;
            printf("\nVertex %c and Vertex %c: ", i + 65, j + 65);
            scanf("%d", &w);
            if(w == 0) continue;
            struct Edge *edge = (struct Edge *)malloc(sizeof(struct Edge));
            edge->src = i;
            edge->dst = j;
            edge->weight = w;
            Edges[edge_counter] = edge;
            edge_counter++;
        }
    }
    finding_mst(Edges, num_of_vrtx, edge_counter);
}
