<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<!-- NewPage -->
<html lang="en">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Uses of Class org.apache.hadoop.hbase.regionserver.wal.CompressionContext (Apache HBase 1.4.13 API)</title>
<link rel="stylesheet" type="text/css" href="../../../../../../../stylesheet.css" title="Style">
</head>
<body>
<script type="text/javascript"><!--
    try {
        if (location.href.indexOf('is-external=true') == -1) {
            parent.document.title="Uses of Class org.apache.hadoop.hbase.regionserver.wal.CompressionContext (Apache HBase 1.4.13 API)";
        }
    }
    catch(err) {
    }
//-->
</script>
<noscript>
<div>JavaScript is disabled on your browser.</div>
</noscript>
<!-- ========= START OF TOP NAVBAR ======= -->
<div class="topNav"><a name="navbar_top">
<!--   -->
</a><a href="#skip-navbar_top" title="Skip navigation links"></a><a name="navbar_top_firstrow">
<!--   -->
</a>
<ul class="navList" title="Navigation">
<li><a href="../../../../../../../overview-summary.html">Overview</a></li>
<li><a href="../package-summary.html">Package</a></li>
<li><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">Class</a></li>
<li class="navBarCell1Rev">Use</li>
<li><a href="../package-tree.html">Tree</a></li>
<li><a href="../../../../../../../deprecated-list.html">Deprecated</a></li>
<li><a href="../../../../../../../index-all.html">Index</a></li>
<li><a href="../../../../../../../help-doc.html">Help</a></li>
</ul>
</div>
<div class="subNav">
<ul class="navList">
<li>Prev</li>
<li>Next</li>
</ul>
<ul class="navList">
<li><a href="../../../../../../../index.html?org/apache/hadoop/hbase/regionserver/wal/class-use/CompressionContext.html" target="_top">Frames</a></li>
<li><a href="CompressionContext.html" target="_top">No Frames</a></li>
</ul>
<ul class="navList" id="allclasses_navbar_top">
<li><a href="../../../../../../../allclasses-noframe.html">All Classes</a></li>
</ul>
<div>
<script type="text/javascript"><!--
  allClassesLink = document.getElementById("allclasses_navbar_top");
  if(window==top) {
    allClassesLink.style.display = "block";
  }
  else {
    allClassesLink.style.display = "none";
  }
  //-->
</script>
</div>
<a name="skip-navbar_top">
<!--   -->
</a></div>
<!-- ========= END OF TOP NAVBAR ========= -->
<div class="header">
<h2 title="Uses of Class org.apache.hadoop.hbase.regionserver.wal.CompressionContext" class="title">Uses of Class<br>org.apache.hadoop.hbase.regionserver.wal.CompressionContext</h2>
</div>
<div class="classUseContainer">
<ul class="blockList">
<li class="blockList">
<table border="0" cellpadding="3" cellspacing="0" summary="Use table, listing packages, and an explanation">
<caption><span>Packages that use <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a></span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Package</th>
<th class="colLast" scope="col">Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colFirst"><a href="#org.apache.hadoop.hbase.regionserver.wal">org.apache.hadoop.hbase.regionserver.wal</a></td>
<td class="colLast">&nbsp;</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><a href="#org.apache.hadoop.hbase.wal">org.apache.hadoop.hbase.wal</a></td>
<td class="colLast">&nbsp;</td>
</tr>
</tbody>
</table>
</li>
<li class="blockList">
<ul class="blockList">
<li class="blockList"><a name="org.apache.hadoop.hbase.regionserver.wal">
<!--   -->
</a>
<h3>Uses of <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a> in <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/package-summary.html">org.apache.hadoop.hbase.regionserver.wal</a></h3>
<table border="0" cellpadding="3" cellspacing="0" summary="Use table, listing fields, and an explanation">
<caption><span>Fields in <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/package-summary.html">org.apache.hadoop.hbase.regionserver.wal</a> declared as <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a></span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Modifier and Type</th>
<th class="colLast" scope="col">Field and Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colFirst"><code>protected <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a></code></td>
<td class="colLast"><span class="strong">WALCellCodec.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALCellCodec.html#compression">compression</a></strong></code>&nbsp;</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><code>protected <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a></code></td>
<td class="colLast"><span class="strong">ReaderBase.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/ReaderBase.html#compressionContext">compressionContext</a></strong></code>
<div class="block">Compression context to use reading.</div>
</td>
</tr>
<tr class="altColor">
<td class="colFirst"><code>protected <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a></code></td>
<td class="colLast"><span class="strong">WriterBase.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WriterBase.html#compressionContext">compressionContext</a></strong></code>&nbsp;</td>
</tr>
</tbody>
</table>
<table border="0" cellpadding="3" cellspacing="0" summary="Use table, listing methods, and an explanation">
<caption><span>Methods in <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/package-summary.html">org.apache.hadoop.hbase.regionserver.wal</a> with parameters of type <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a></span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Modifier and Type</th>
<th class="colLast" scope="col">Method and Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colFirst"><code>static <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALCellCodec.html" title="class in org.apache.hadoop.hbase.regionserver.wal">WALCellCodec</a></code></td>
<td class="colLast"><span class="strong">WALCellCodec.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALCellCodec.html#create(org.apache.hadoop.conf.Configuration,%20org.apache.hadoop.hbase.regionserver.wal.CompressionContext)">create</a></strong>(org.apache.hadoop.conf.Configuration&nbsp;conf,
      <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a>&nbsp;compression)</code>
<div class="block">Create and setup a <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALCellCodec.html" title="class in org.apache.hadoop.hbase.regionserver.wal"><code>WALCellCodec</code></a> from the
 CompressionContext.</div>
</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><code>static <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALCellCodec.html" title="class in org.apache.hadoop.hbase.regionserver.wal">WALCellCodec</a></code></td>
<td class="colLast"><span class="strong">WALCellCodec.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALCellCodec.html#create(org.apache.hadoop.conf.Configuration,%20java.lang.String,%20org.apache.hadoop.hbase.regionserver.wal.CompressionContext)">create</a></strong>(org.apache.hadoop.conf.Configuration&nbsp;conf,
      <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;cellCodecClsName,
      <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a>&nbsp;compression)</code>
<div class="block">Create and setup a <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALCellCodec.html" title="class in org.apache.hadoop.hbase.regionserver.wal"><code>WALCellCodec</code></a> from the <code>cellCodecClsName</code> and
 CompressionContext, if <code>cellCodecClsName</code> is specified.</div>
</td>
</tr>
<tr class="altColor">
<td class="colFirst"><code>protected <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALCellCodec.html" title="class in org.apache.hadoop.hbase.regionserver.wal">WALCellCodec</a></code></td>
<td class="colLast"><span class="strong">ProtobufLogWriter.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/ProtobufLogWriter.html#getCodec(org.apache.hadoop.conf.Configuration,%20org.apache.hadoop.hbase.regionserver.wal.CompressionContext)">getCodec</a></strong>(org.apache.hadoop.conf.Configuration&nbsp;conf,
        <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a>&nbsp;compressionContext)</code>&nbsp;</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><code>protected <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALCellCodec.html" title="class in org.apache.hadoop.hbase.regionserver.wal">WALCellCodec</a></code></td>
<td class="colLast"><span class="strong">ProtobufLogReader.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/ProtobufLogReader.html#getCodec(org.apache.hadoop.conf.Configuration,%20java.lang.String,%20org.apache.hadoop.hbase.regionserver.wal.CompressionContext)">getCodec</a></strong>(org.apache.hadoop.conf.Configuration&nbsp;conf,
        <a href="http://docs.oracle.com/javase/7/docs/api/java/lang/String.html?is-external=true" title="class or interface in java.lang">String</a>&nbsp;cellCodecClsName,
        <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a>&nbsp;compressionContext)</code>&nbsp;</td>
</tr>
<tr class="altColor">
<td class="colFirst"><code>void</code></td>
<td class="colLast"><span class="strong">WALEdit.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALEdit.html#setCompressionContext(org.apache.hadoop.hbase.regionserver.wal.CompressionContext)">setCompressionContext</a></strong>(<a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a>&nbsp;compressionContext)</code>&nbsp;</td>
</tr>
</tbody>
</table>
<table border="0" cellpadding="3" cellspacing="0" summary="Use table, listing constructors, and an explanation">
<caption><span>Constructors in <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/package-summary.html">org.apache.hadoop.hbase.regionserver.wal</a> with parameters of type <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a></span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colOne" scope="col">Constructor and Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colLast"><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/SecureWALCellCodec.html#SecureWALCellCodec(org.apache.hadoop.conf.Configuration,%20org.apache.hadoop.hbase.regionserver.wal.CompressionContext)">SecureWALCellCodec</a></strong>(org.apache.hadoop.conf.Configuration&nbsp;conf,
                  <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a>&nbsp;compression)</code>&nbsp;</td>
</tr>
<tr class="rowColor">
<td class="colLast"><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/WALCellCodec.html#WALCellCodec(org.apache.hadoop.conf.Configuration,%20org.apache.hadoop.hbase.regionserver.wal.CompressionContext)">WALCellCodec</a></strong>(org.apache.hadoop.conf.Configuration&nbsp;conf,
            <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a>&nbsp;compression)</code>
<div class="block">Default constructor - <b>all subclasses must implement a constructor with this signature </b>
 if they are to be dynamically loaded from the <code>Configuration</code>.</div>
</td>
</tr>
</tbody>
</table>
</li>
<li class="blockList"><a name="org.apache.hadoop.hbase.wal">
<!--   -->
</a>
<h3>Uses of <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a> in <a href="../../../../../../../org/apache/hadoop/hbase/wal/package-summary.html">org.apache.hadoop.hbase.wal</a></h3>
<table border="0" cellpadding="3" cellspacing="0" summary="Use table, listing fields, and an explanation">
<caption><span>Fields in <a href="../../../../../../../org/apache/hadoop/hbase/wal/package-summary.html">org.apache.hadoop.hbase.wal</a> declared as <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a></span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Modifier and Type</th>
<th class="colLast" scope="col">Field and Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colFirst"><code>protected <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a></code></td>
<td class="colLast"><span class="strong">WALKey.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/wal/WALKey.html#compressionContext">compressionContext</a></strong></code>&nbsp;</td>
</tr>
</tbody>
</table>
<table border="0" cellpadding="3" cellspacing="0" summary="Use table, listing methods, and an explanation">
<caption><span>Methods in <a href="../../../../../../../org/apache/hadoop/hbase/wal/package-summary.html">org.apache.hadoop.hbase.wal</a> with parameters of type <a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a></span><span class="tabEnd">&nbsp;</span></caption>
<tr>
<th class="colFirst" scope="col">Modifier and Type</th>
<th class="colLast" scope="col">Method and Description</th>
</tr>
<tbody>
<tr class="altColor">
<td class="colFirst"><code>void</code></td>
<td class="colLast"><span class="strong">WALKey.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/wal/WALKey.html#setCompressionContext(org.apache.hadoop.hbase.regionserver.wal.CompressionContext)">setCompressionContext</a></strong>(<a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a>&nbsp;compressionContext)</code>&nbsp;</td>
</tr>
<tr class="rowColor">
<td class="colFirst"><code>void</code></td>
<td class="colLast"><span class="strong">WAL.Entry.</span><code><strong><a href="../../../../../../../org/apache/hadoop/hbase/wal/WAL.Entry.html#setCompressionContext(org.apache.hadoop.hbase.regionserver.wal.CompressionContext)">setCompressionContext</a></strong>(<a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">CompressionContext</a>&nbsp;compressionContext)</code>
<div class="block">Set compression context for this entry.</div>
</td>
</tr>
</tbody>
</table>
</li>
</ul>
</li>
</ul>
</div>
<!-- ======= START OF BOTTOM NAVBAR ====== -->
<div class="bottomNav"><a name="navbar_bottom">
<!--   -->
</a><a href="#skip-navbar_bottom" title="Skip navigation links"></a><a name="navbar_bottom_firstrow">
<!--   -->
</a>
<ul class="navList" title="Navigation">
<li><a href="../../../../../../../overview-summary.html">Overview</a></li>
<li><a href="../package-summary.html">Package</a></li>
<li><a href="../../../../../../../org/apache/hadoop/hbase/regionserver/wal/CompressionContext.html" title="class in org.apache.hadoop.hbase.regionserver.wal">Class</a></li>
<li class="navBarCell1Rev">Use</li>
<li><a href="../package-tree.html">Tree</a></li>
<li><a href="../../../../../../../deprecated-list.html">Deprecated</a></li>
<li><a href="../../../../../../../index-all.html">Index</a></li>
<li><a href="../../../../../../../help-doc.html">Help</a></li>
</ul>
</div>
<div class="subNav">
<ul class="navList">
<li>Prev</li>
<li>Next</li>
</ul>
<ul class="navList">
<li><a href="../../../../../../../index.html?org/apache/hadoop/hbase/regionserver/wal/class-use/CompressionContext.html" target="_top">Frames</a></li>
<li><a href="CompressionContext.html" target="_top">No Frames</a></li>
</ul>
<ul class="navList" id="allclasses_navbar_bottom">
<li><a href="../../../../../../../allclasses-noframe.html">All Classes</a></li>
</ul>
<div>
<script type="text/javascript"><!--
  allClassesLink = document.getElementById("allclasses_navbar_bottom");
  if(window==top) {
    allClassesLink.style.display = "block";
  }
  else {
    allClassesLink.style.display = "none";
  }
  //-->
</script>
</div>
<a name="skip-navbar_bottom">
<!--   -->
</a></div>
<!-- ======== END OF BOTTOM NAVBAR ======= -->
<p class="legalCopy"><small>Copyright &#169; 2007&#x2013;2020 <a href="https://www.apache.org/">The Apache Software Foundation</a>. All rights reserved.</small></p>
</body>
</html>
