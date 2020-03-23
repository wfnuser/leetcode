class Solution
{
    Map<String, Boolean> vis = new HashMap<>();
    List<String> gans = new ArrayList<>();
    static HtmlParser htmlparser;
    private List<String> getNextVertixes(String u) {
        return htmlparser.getUrls(u);
    }
    public List<String> crawl(String startUrl, HtmlParser htmlParser) {
        this.htmlparser = htmlParser;
        dfs(startUrl);
        return gans;
    }
    private boolean isSameHost(String u, String v) {
        return u.split("/")[2].equals(v.split("/")[2]);
    }
    private void dfs(String u)
    {
        synchronized (vis) {
            if( vis.containsKey(u)) return ;
            vis.put(u, true);
        }
        synchronized (gans) {
            gans.add(u);
        }
        List<String> nexts = getNextVertixes(u);
        List<Thread> threads = new ArrayList<>();
        for( String v: nexts) {
            if( !isSameHost(u, v)) continue;
            Thread t = new Thread(()-> dfs(v));
            threads.add(t);  t.start();
        }
        try { for( Thread t :threads) t.join(); } 
          catch(InterruptedException e) 
          { e.printStackTrace(); }
    }
}